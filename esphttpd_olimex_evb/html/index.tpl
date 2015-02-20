<html>
<head><title>Esp8266 web server</title>
<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<div id="main">
<h1>It Relay Example</h1>
<p>
This is example for OLIMEX evb board. You can turn on or off relay. Also green led on the board signalize relay state.
<b>state of relay is %relay_state%</b>
<ul>
<li>If you haven't connected this device to your WLAN network now, you can <a href="/wifi">do so.</a></li>
</ul>
</p>

<form method="post" action="relay.cgi">
<input type="submit" size=200 name="RelayLed" value="1">
<input type="submit" name="RelayLed" value="0">

<input type="button" name="Relay" value="ahoj" onclick="myFunction(this, 'red')">

<script>
function myFunction(elmnt,clr) {
    elmnt.style.color = clr;
}
</script>

</form>

</div>
</body></html>
