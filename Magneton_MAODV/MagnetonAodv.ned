// AODV Protocol- Alon and Avidan
//CheckCheck
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.node.inet.StandardHost;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
//import inet.node.ethernet.Eth100M;
import ned.DatarateChannel;
import inet.routing.aodv.Aodv;
import inet.linklayer.ethernet.EtherHub;


network AODVNetwork
{
    parameters:
        int numHosts;
        @display("bgb=650,650;bgi=background/streetmap;bgu=m");
	
	types:
	    channel ethline extends DatarateChannel
        {
            delay = 50ns;
            datarate = 100Mbps;
        }
	    
    submodules:

        radioMedium: UnitDiskRadioMedium {
            parameters:
                @display("p=98.1,26.16;is=s");
        }
        
        
        configurator: Ipv4NetworkConfigurator {
            parameters:
			config = xml("<config><interface hosts='*' address='145.236.x.x' netmask='255.255.x.x'/></config>");                @display("p=100,100;is=s");
                
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=218.43599,28.776;is=s");
        }
        
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=218.43599,113.796;is=s");
        }
        
        host[numHosts]: AodvRouter {
            parameters:
					
                @display("i=device/satellite");
                aodv.activeRouteTimeout = 6s;
                interfaceTable.displayAddresses = true;
                aodv.ttlStart = 1;
                numWlanInterfaces=0;
                numEthInterfaces=3;
                aodv.interface = "eth0";
        }
        hostSendHub[numHosts]: EtherHub{

                       }
        
    connections allowunconnected:
        for i=0..numHosts-2 {
            host[i].ethg[0] <--> ethline <--> hostSendHub[i].ethg++;
            host[i].ethg[1] <--> ethline <--> hostSendHub[i+1].ethg++;
            hostSendHub[i].ethg++<--> ethline <--> host[i+1].ethg[2];
           
            
            
        }
}
