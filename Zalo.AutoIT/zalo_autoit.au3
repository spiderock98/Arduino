#include<ImageSearch.au3>

While 1
	Local $x=0, $y=0
	;green_on
	Local $search1 = _ImageSearch(@ScriptDir&'\green_on.bmp',1,$x,$y,0)
	If $search1=1 Then
		WinActivate('COM3 (Arduino/Genuino Uno)')
		Send('1'&'{ENTER}')
	EndIf

	;green_off
	Local $search2 = _ImageSearch(@ScriptDir&'\green_off.bmp',1,$x,$y,0)
	If $search2=1 Then
		WinActivate('COM3 (Arduino/Genuino Uno)')
		Send('2'&'{ENTER}')
	EndIf
	;red_on
	Local $search3 = _ImageSearch(@ScriptDir&'\red_on.bmp',1,$x,$y,0)
	If $search3=1 Then
		WinActivate('COM3 (Arduino/Genuino Uno)')
		Send('3'&'{ENTER}')
	EndIf
	;red_off
	Local $search4 = _ImageSearch(@ScriptDir&'\red_off.bmp',1,$x,$y,0)
	If $search4=1 Then
		WinActivate('COM3 (Arduino/Genuino Uno)')
		Send('4'&'{ENTER}')
	EndIf
	;yellow_on
	Local $search5 = _ImageSearch(@ScriptDir&'\yellow_on.bmp',1,$x,$y,0)
	If $search5=1 Then
		WinActivate('COM3 (Arduino/Genuino Uno)')
		Send('5'&'{ENTER}')
	EndIf
	;yellow_off
	Local $search6 = _ImageSearch(@ScriptDir&'\yellow_off.bmp',1,$x,$y,0)
	If $search6=1 Then
		WinActivate('COM3 (Arduino/Genuino Uno)')
		Send('6'&'{ENTER}')
	EndIf
	;ON_ALL
	Local $search7 = _ImageSearch(@ScriptDir&'\ON_ALL.bmp',1,$x,$y,0)
	If $search7=1 Then
		WinActivate('COM3 (Arduino/Genuino Uno)')
		Send('7'&'{ENTER}')
	EndIf
	;OFF_ALL
	Local $search7 = _ImageSearch(@ScriptDir&'\OFF_ALL.bmp',1,$x,$y,0)
	If $search7=1 Then
		WinActivate('COM3 (Arduino/Genuino Uno)')
		Send('8'&'{ENTER}')
	EndIf
WEnd