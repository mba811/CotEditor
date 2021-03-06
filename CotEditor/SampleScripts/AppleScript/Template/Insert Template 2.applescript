(*
Insert Template 2.applescript
Sample Script for CotEditor

Description:
Replaces the selection of the frontmost window with a user-defined string, then places the caret right after the inserted string.

最前面のウィンドウの選択範囲を設定された文字列で置き換え、キャレットを置き換えられた文字列の直後に移動します。

written by nakamuxu on 2005-04-14
modified by 1024jp on 2014-11-22
*)

property newStr : "TEMPLATE" -- string to insert

--
tell application "CotEditor"
	if not (exists front document) then return
	
	tell front document
		-- calculate location to set cursor after the insertion
		set {loc, len} to range of selection
		set numOfMove to count of character of newStr
		
		-- replace selected text with the template text
		set contents of selection to newStr
		
		-- move the cursor to just after the inserted text
		set range of selection to {loc + numOfMove, 0}
	end tell
end tell
