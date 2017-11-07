#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.
#MaxThreadsPerHotkey 2

toggle := false
targetChannel := "#slotstuff"

::fi::t{!}fish

::fii::t{!}fish inventory

::fis::
	Send, t{!}fish sell trash
	Send, {Enter}
	Sleep, 6000
	Send, t{!}fish sell common
	Send, {Enter}
	Sleep, 6000
	Send, t{!}fish sell uncommon
	Send, {Enter}
Return	


^F2::
	IfWinActive, %targetChannel% - Discord
	{
		toggle := !toggle
		if(toggle){
			Send, Autofishing enabled.
			Send, {Enter}
		} else {
			Send, Autofishing disabled.
			Send, {Enter}
		}
	} else {
		MsgBox, Discord not active or in wrong channel.
		toggle := false
	}
	
	while(toggle)
	{
		IfWinActive, %targetChannel% - Discord
		{
			Send, t{!}fish
			Send, {Enter}
			Sleep, 30000
		} else {
			toggle := false
			MsgBox, Autofishing automagically disabled.
			break
		}
	}
Return
