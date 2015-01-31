
 
function PrintThisPage()
{
    print();
}




function resizeWindow()
{
   if(confirm("Are you sure"))
      resizeTo(300,300);
}
function moveWindow()
{
   if(confirm("Are you sure"))
      moveTo(300,300);
}

function openWindow()
{
    window.open("events.html","events","width=700 height=400 resizable");
}



function closeCurrentWindow()
{
    if(confirm("Are you sure"))
    close();
}

function alertMessage()
{
   alert("Hello user !!!");
}

var tid;
function setIntervalForColor()
{
   tid=window.setInterval("changeColor()",2000);
}

function clearIntervalForColor()
{
   window.clearInterval(tid);
}
var counter=0;
function changeColor()
{
    if(counter==0)
      document.body.bgColor="blue";
    else if(counter==1)
       document.body.bgColor="red";
    else if(counter==2)
      document.body.bgColor="orange";
    else if(counter==3)
      document.body.bgColor="pink";
    counter++;
    if(counter==4)
    counter=0;
}


