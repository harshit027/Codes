<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>
</head>

<body>

<?php
$names=array("John","Smith","Peter","Michael");
print("<u>Accessing arrays by index ::<br><br></u>");
print($names[0]."//".$names[1]."//".$names[2]."//".$names[3]."//");
print("<br><br><hr>");
$attributes=array(name=>"John",age=>"30",place=>"London",occupation=>"CA");
print("<u>Declaring Associative arrays ::</u><br><br>"); 
print("Name : $attributes[name]<br>Age : $attributes[age]<br>Place : $attributes[place]<br>Occupation : $attributes[occupation]<br><br><hr>");

$character[name] = "bob";
$character[occupation] = "superhero";
$character[age] = 30;
$character["special power"] = "x-ray vision";

print("<u>Declaring Associative arrays directly ::</u><br><br>"); 
print("Name : $character[name]<br>Age : $character[age]<br>Place : $character[place]<br>Occupation : $character[occupation]<hr>");

$employees=array(
array ( name=>"bob",
 occupation=>"superhero",
 age=>30,
 specialty=>"x-ray vision" ),
 array ( name=>"sally",
 occupation=>"superhero",
 age=>24,
 specialty=>"superhuman strength" ),
 array ( name=>"mary",
 occupation=>"arch villain",
 age=>63,
 specialty=>"nanotechnology" )
 );
 
 print("<br><br>Multidimensional arrays<br><br>");
 print("<table border='1' cellspacing='0'>
 <tr>
 <th>Name</th>
 <th>Occupation</th>
 <th>Age</th>
 <th>Speciality</th>
 </tr>
 ");
 for($i=0;$i<count($employees);$i++)
 print("
 <tr>
 <td>".$employees[$i][name]."</td>
 <td>".$employees[$i][occupation]."</td>
 <td>".$employees[$i][age]."</td>
 <td>".$employees[$i][specialty]."</td>
 </tr>");
 print("</table><hr>");
 
 print("<br><br><u>Accessing through fro each</u><br><br>");
$users = array ("Bert", "Sharon", "Betty", "Harry" );
foreach ( $users as $val )
{
print "$val:::";
}
print("<hr><br><br><u>Merging two array using array_merge()</u><br><br>");
$arr1=array("a","b","c");
$arr2=array(1,2,3);
$arr3=array_merge($arr1,$arr2);
foreach($arr3 as $val)
{
print $val."---";
}
print("<hr><br><br><u>Pushing elements in array using array_push()</u><br><br>");
$arr4=array("a","b","c");
array_push($arr4,1,2);
foreach($arr4 as $val)
{
print $val."---";
}
print("<hr><br><br><u>Shifting first element in array using array_shift()</u><br><br>");
$arr5 = array("a", "b", "c");
while ( count( $arr5) )
{
$val = array_shift( $arr5);
print "$val<BR>";
print "there are ".count($arr5)." elements in \$arr5 <br>";
}
   
print("<hr><br><br><u>Slicing array using array_slice()</u> <br><br>");
$arr6=array("a","b","c","d","e","f");
$arr7=array_slice($arr6,2,3);
foreach($arr7 as $val)
print $val."---";


print("<hr><br><br><u>Sorting array using sort()</u> <br><br>");
$arr8=array("b","c","d","a");
print("Original array :");
foreach($arr8 as $val)
print $val."---";
sort($arr8);

print("Sorted array :");
foreach($arr8 as $val)
print $val."---";

print("<hr><br><br><u>Sorting associative array using asort()</u> <br><br>");
$arr9= array("first"=>5,"second"=>2,"third"=>1);
asort( $arr9);
foreach ( $arr9 as $key => $val )
{
print "$key = $val<BR>";
}

print("<hr><br><br><u>Sorting associative array using ksort()</u> <br><br>");
$arr10 = array("x"=>5,"a"=>2,"f"=>1);
ksort( $arr10);
foreach ( $arr10 as $key => $val )
{
print "$key = $val<BR>";
}
?>
</body>
</html>
