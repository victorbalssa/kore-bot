<?php 
require_once('configuration.php');
require_once('functions.php');
?>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
		<link rel="stylesheet" href="css/style.css" />
        <title>KORBOT REMOTE</title>
    </head>
	
 
    <body style="background-color:#84B6FB">
	 <img class="stream" src="http://192.168.1.11:8080/?action=stream" width="80%" height="70%" alt="direct stream by NAND">
	 <?php
	 //this php script generate the first page in function of the gpio's status
	 $status = array (0, 0, 0, 0);
	 for ($i = 0; $i < count($status); $i++) {
		//set the pin's mode to output and read them
		system("gpio mode ".$i." out");
		exec ("gpio read ".$i, $status[$i], $return );
		//if off
		if ($status[$i][0] == 0 ) {
			if($i == 0){
				echo ("<table><tr><td></td><td><img id='boutonimage_0' src='data/img/red/red_0.png' alt='off'/></td><td></td></tr>");}
			if($i == 1){
				echo ("<tr><td><img id='boutonimage_1' src='data/img/red/red_1.png' alt='off'/></td><td></td>");}
			if($i == 2){
				echo ("<td><img id='boutonimage_2' src='data/img/red/red_2.png' alt='off'/></td></tr>");}	
			if($i == 3){
				echo ("<tr><td></td><td><img id='boutonimage_3' src='data/img/red/red_3.png' alt='off'/></td><td></td></tr></table>");}	
		}
		//if on
		if ($status[$i][0] == 1 ) {
		echo ("<img id='boutonimage_".$i."' src='data/img/green/green_".$i.".png' alt='on'/>");
		}	 
	 }
	 ?>
	 <input type="button" style="width:150px" value="STREAM"
		onclick="stream()"
	 />
	 <!-- javascript -->
	 <script src="script.js"></script>
	 <script src="js/jquery.min.js"></script>
     <script src="js/script.js"></script>
	 </body>
</html>