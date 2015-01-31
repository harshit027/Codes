function writeOnDocument()
{
   document.write("This is written by write() ");
}

function writeInOnDocument()
{
   document.writeIn("This is written by writeIn() ");
}

function accessingElementsByID()
{
    var obj=document.getElementById("div1");
    obj.style.backgroundColor='#ff0000';
    
}

function accessingElementsByName()
{
    var obj1=document.getElementByName("div2");
    obj1.style.backgroundColor='#00ff00';

}