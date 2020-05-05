$PowerEventInfo=EventLog -LogName System -Source Microsoft-Windows-Power-Troubleshooter -Newest 1 | Out-String
$PowerEventInfoCurrent=$PowerEventInfo
$Player=New-Object Media.SoundPlayer \"silence.wav\"

while ($true) {
	$Player.PlayLooping()
	while ($PowerEventInfo -like $PowerEventInfoCurrent) {
		$PowerEventInfoCurrent=EventLog -LogName System -Source Microsoft-Windows-Power-Troubleshooter -Newest 1 | Out-String
		Start-Sleep -s 15
	}
	$PowerEventInfo=$PowerEventInfoCurrent
	$Player.Stop()
}