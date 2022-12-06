#include <stdio.h>
#include <sqlite3.h>

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

    // ランダムにアイテムを取得 
    char *select_sql = "SELECT * FROM items ORDER BY RANDOM() LIMIT 1;";
    rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, 0);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    int step = sqlite3_step(stmt);
    if (step == SQLITE_ROW) {
        printf("%s\n", sqlite3_column_text(stmt, 1));
    } 

    sqlite3_finalize(stmt);

    // 取得したデータをカゴに入れる
    char *insert_sql = "INSERT INTO basket(id, item_id) values (null, ?);";
    rc = sqlite3_prepare_v2(db, insert_sql, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlite3_bind_int(stmt, 1, 1);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}
