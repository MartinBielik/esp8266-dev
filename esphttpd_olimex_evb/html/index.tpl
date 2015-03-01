<html>
<head><title>Esp8266 web server</title>
<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<div id="main">
<h1>It Relay Example</h1>
<p>
This is example for OLIMEX evb board. You can turn on or off relay. Also green led on the board signalize relay state.
<ul>
<li>If you haven't connected this device to your WLAN network now, you can <a href="/wifi">do so.</a></li>
</ul>
</p>

<p id="text">
<input id="chb1" type="checkbox" name="state" checked disabled>
<script>
if (%relay_state%) {
  document.getElementById("chb1").checked=true;
  document.write("Relay is switched <font size=\"3\" color=\"green\">ON</font>");
}
else {
  document.getElementById("chb1").checked=false;
  document.write("Relay is switched <font size=\"3\" color=\"red\">OFF</font>");
}
</script> 
</p>

<form method="post" action="relay.cgi">
<input type="submit" name="RelayLed" value="1">
<input type="submit" name="RelayLed" value="0">
</form>

</div>
</body></html>
