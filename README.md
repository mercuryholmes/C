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

データベースとテーブルの作成

```bash
cd ./data
sqlite3 atelier.db < table.sql
```

データの投入
```bash
sqlite3 atelier.db < seed.sql
```
