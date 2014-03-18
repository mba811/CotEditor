
changelog (for developer)
==========================

1.5
--------------------------
- 移動パネルの行／文字選択がラジオボタンからポップアップボタンに
- ウインドウの透明化に関する変更
	- ウインドウ全体の透明化の廃止
	- 行番号ビューもテキストビューに合わせて透過
	- 「透明度 (transparency)」を「不透明度 (opacity)」に修正
	- ウインドウ透明パネルの名前をウインドウ不透明度パネルに変更
	- 不透明度パネルの「全ウインドウに適応」ボタンを「デフォルトとして保存」に変更し、現在のウインドウに適応するだけではなくデフォルトとしても保存されるように変更

- AppleScriptに関する変更
	- documentオブジェクトの `transparency` および `alpha only textView` プロパティの廃止
	- windowオブジェクトに `view opacity` プロパティを追加