#Note that:
>1.  All light pos transform/scale/rotate in same space(world-space or view-space)

>2.  Watch out the viewer direction and light direction in specular lighting.

>3.  Gouraud shading is change light color in Vertex shader and pass to fragment shader but the color values of the surrounding fragments are then the result of interpolated lighting color.

>4.  To simulate different type of objects, we can define material properties
to each objects.As a simple example,it can only contain 4 light components including ambient/diffuse/specular lighting and a shininess(used in specular's calculation,determin the size of hightlight spot.)

>5.  We can also define a light struct just as 4th point does.Pay attention to the strength of the different lighting component.  

>6.  Diffuse/Specular/Emission Map can simulate some relatively complex real objects which may contains some seperate parts those have different diffuse or specular attributes.

###Extra discoveries
>7.  One saccidental trial cheer me up that we can use specular map to get a effect like invisible potion.
