function change_pin (pin, status) 
{

	//this is the http request

	var request = new XMLHttpRequest();
	request.open( "GET" , "gpio.php?pin=" + pin + "&status=" + status );
	request.send(null);

	//receiving information

	request.onreadystatechange = function () 
             {

		if (request.readyState == 4 && request.status == 200) 
                {
			return (parseInt(request.responseText));
		}
	//test if fail

		else if (request.readyState == 4 && request.status == 500) 
                {
			alert ("server error");
			return ("fail");
		}
	//else 
		else { return ("fail"); }
	     }
}

var button_0 = document.getElementById("boutonimage_0");
var button_1 = document.getElementById("boutonimage_1");
var button_2 = document.getElementById("boutonimage_2");
var button_3 = document.getElementById("boutonimage_3"); 

document.onkeypress = function keypress1(event)
{
     if ( typeof event == "undefined" ) event = window.event

     wkey = event.charCode
     if ( document.layers ) wkey = event.which
     

     if (wkey == 122) // voir ascii oklm en position baissée
     {
	 
	      
      
	if ( button_0.alt === "off" ) {
		//use the function
		var new_status = change_pin ( 0, 0);
		if (new_status !== "fail") { 
			button_0.alt = "on"
			button_0.src = "data/img/green/green_0.png"; 
			return 0;
			}
		}
     }
          
     if (wkey == 113)
     {

       if ( button_1.alt === "off" ) {
		//use the function
		var new_status = change_pin ( 1, 0);
		if (new_status !== "fail") { 
			button_1.alt = "on"
			button_1.src = "data/img/green/green_1.png"; 
			return 0;
			}
		}
     }  
     
     if (wkey == 100)
     {

       if ( button_2.alt === "off" ) {
		//use the function
		var new_status = change_pin ( 2, 0);
		if (new_status !== "fail") { 
			button_2.alt = "on"
			button_2.src = "data/img/green/green_2.png"; 
			return 0;
			}
		}
     }  
     
     if (wkey == 115)
     {

       if ( button_3.alt === "off" ) {
		//use the function
		var new_status = change_pin ( 3, 0);
		if (new_status !== "fail") { 
			button_3.alt = "on"
			button_3.src = "data/img/green/green_3.png"; 
			return 0;
			}
		}
     }       
} 



document.onkeyup = function keyPress2(event) 
{
if ( typeof event == "undefined" ) event = window.event

wkey = event.keyCode
if ( document.layers ) wkey = event.which

      if (wkey == 90) // voir ascii Oklm en position up
     {
          if ( button_0.alt === "on" ) {
		//use the function
		var new_status = change_pin ( 0, 1);
		if (new_status !== "fail") { 
			button_0.alt = "off"
			button_0.src = "data/img/red/red_0.png"; 
			return 0;
			}
		}
     }

     if (wkey == 81) // voir ascii
     {
          if ( button_1.alt === "on" ) {
		//use the function
		var new_status = change_pin ( 1, 1);
		if (new_status !== "fail") { 
			button_1.alt = "off"
			button_1.src = "data/img/red/red_1.png"; 
			return 0;
			}
		}
     }
     
      if (wkey == 68) // voir ascii
     {
          if ( button_2.alt === "on" ) {
		//use the function
		var new_status = change_pin ( 2, 1);
		if (new_status !== "fail") { 
			button_2.alt = "off"
			button_2.src = "data/img/red/red_2.png"; 
			return 0;
			}
		}
     }
       if (wkey == 83) // voir asci
     {
          if ( button_3.alt === "on" ) {
		//use the function
		var new_status = change_pin ( 3, 1);
		if (new_status !== "fail") { 
			button_3.alt = "off"
			button_3.src = "data/img/red/red_3.png"; 
			return 0;
			}
		}
     }
         
}