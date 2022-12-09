# C言語自作ゲーム

## Requirement

* sqlite3 (3.34.1)

## Installation

* sqlite3 (3.34.1)

```bash
sudo apt install sqlite3 -y
```

```bash
sudo apt install libsqlite3-dev
```

## Preparation

* データ準備

データベースとテーブルの作成

```bash
sqlite3 ./data/atelier.db < ./data/table.sql
```

データの投入
```bash
sqlite3 ./data/atelier.db < ./data/seed.sql
```

* コンパイル

```bash
make
```

* 実行

```bash
./bin/atelier
```
