---
auther:yakitori
date:2019/09/13
comment:reveasible hash is not URI encoding.but like a URI encoding.
---

# what.
ツイッターで平文を暗号化するような案件が飛び交っていたので、パスワードを前提に、安全な暗号化を考案した。
ただ、可逆なのでさらにSha256に突っ込むなどしないと復号される。

# looking for...
辞書型エンコーダーなので、適応側の最初の仕様がモノをいう。
設計ミスったら取り返しがつかないやつだ。
辞書をリモートから読めないファイルにして、バージョンを切るのがいいでしょう。

# license.
MITライセンスです。
たまにライセンスを剥奪することがあります。めったにないですが。