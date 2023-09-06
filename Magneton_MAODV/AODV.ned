simple AodvModule
{
    parameters:
        int address;
        
    gates:
        input in;
        output out;
}

network SimpleAodvNetwork
{
    @display("bgb=600,400;bgi=background/terrain");

    submodules:

        // Three ad hoc hosts
        A: AodvModule {
            address = 1;
            @display("p=138,203;i=device/satellite;is=l");
        }
        B: AodvModule {
            address = 2;
            @display("p=234,163;i=device/satellite;is=l");
        }
        C: AodvModule {
            address = 3;
            @display("p=345,105;i=device/satellite;is=l");
        }
        D: AodvModule {
            address = 4;
            @display("p=435,178;i=device/satellite;is=l");
        }
        E: AodvModule {
            address = 5;
            @display("p=336,228;i=device/satellite;is=l");
        }
        F: AodvModule {
            address = 6;
            @display("p=221,286;i=device/satellite;is=l");
        }

    connections:
        A.out --> {  delay = 100ms; } --> B.in;
        A.in <-- {  delay = 100ms; } <-- B.out;
        B.out --> {  delay = 100ms; } --> C.in;
        B.in <-- {  delay = 100ms; } <-- C.out;
        C.out --> {  delay = 100ms; } --> D.in;
        C.in <-- {  delay = 100ms; } <-- D.out;
        D.in <-- {  delay = 100ms; } <-- C.out;
        D.out --> {  delay = 100ms; } --> E.in;
        D.in <-- {  delay = 100ms; } <-- E.out;
        F.out --> {  delay = 100ms; } --> E.in;
        F.in <-- {  delay = 100ms; } <-- E.out;

}

