max_height = 10;

module leg()
{
    difference()
    {
        union()
        {
            cylinder(4,11,11);
            translate([0,0,4])cylinder(6,11,5);
        }
        translate([0,0,8])cylinder(3,4,4);
        translate([0,0,-1])cylinder(5,2,2);
    }
}
// top plate
difference()
{
    // base shape
    linear_extrude(height = max_height, center = false, convexity = 10)
        import (file = "layoutANSI60.dxf", layer = "out_line");   
    // switch cutouts
    translate([0,0,-0.5])
        linear_extrude(height = max_height+1, center = false, convexity = 10)
            import (file = "layoutANSI60.dxf", layer = "cut_true");    
    // 8.5mm pocket
    translate([0,0,-0.5])
        linear_extrude(height = 8.6+0.5, center = false, convexity = 10)
            import (file = "layoutANSI60.dxf", layer = "pocket_8.6mm");   
    // 2mm pocket
    translate([0,0,-0.5])
        linear_extrude(height = 2+0.5, center = false, convexity = 10)
            import (file = "layoutANSI60.dxf", layer = "pocket_2mm"); 
    // m2.5 threats
    translate([0,0,-0.5])
        linear_extrude(height = max_height-1.5+0.5, center = false, convexity = 10, $fn = 10)
            import (file = "layoutANSI60.dxf", layer = "M2.5_1.5mm");
}

// bottom plate
difference()
{
    //base shape
    linear_extrude(height = 2, center = false, convexity = 10)
        import (file = "layoutANSI60_bottom_plate.dxf", layer = "out_line");
    //cutouts
    translate([0,0,-0.5])
        linear_extrude(height = 2+1, center = false, convexity = 10, $fn = 10)
            import (file = "layoutANSI60_bottom_plate.dxf", layer = "cut_true");
    //adesive legs place
    translate([0,0,-0.5])
        linear_extrude(height = 0.5+0.5, center = false, convexity = 10)
            import (file = "layoutANSI60_bottom_plate.dxf", layer = "pocket_-0.5mm");
}

//legs
translate([9.5,89,0])mirror([0,0,1])leg();
translate([275.5,89,0])mirror([0,0,1])leg();

//PCB
translate([1.9,2.1,4])
    import(file = "keyboard_PCB.stl");

