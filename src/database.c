#include <stdio.h>
#include <sqlite3.h>
#include "include/function.h"
#include "include/define.h"

char *database = "./data/atelier.db";

int get_item_at_random(void) {

    sqlite3 *db;
    sqlite3_stmt *stmt;

    // データベースに接続
    int rc = sqlite3_open(database, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr,"Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // 取得するアイテムを決定
    char *select_items_sql = "SELECT * FROM items ORDER BY RANDOM() LIMIT 1;";
    rc = sqlite3_prepare_v2(db, select_items_sql, -1, &stmt, 0);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // 取得するアイテムを表示
    int item_id;

    int step = sqlite3_step(stmt);
    if (step == SQLITE_ROW) {
        item_id = sqlite3_column_int(stmt, 0);
        printf("%s\n", sqlite3_column_text(stmt, 1));
    }

    sqlite3_finalize(stmt);

    // アイテムを取得して保存
    int quality = generate_random(MIN_QUALITY, MAX_QUALITY);

    char *insert_user_items_sql = "INSERT INTO user_items(item_id, quality) values (?, ?);";
    rc = sqlite3_prepare_v2(db, insert_user_items_sql, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlite3_bind_int(stmt, 1, item_id);
    sqlite3_bind_int(stmt, 2, quality);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlite3_finalize(stmt);

    // 取得したアイテムをカゴに入れる
    int usert_item_id = sqlite3_last_insert_rowid(db);

    char *insert_basket_sql = "INSERT INTO basket(user_item_id) values (?);";
    rc = sqlite3_prepare_v2(db, insert_basket_sql, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlite3_bind_int(stmt, 1, usert_item_id);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}
