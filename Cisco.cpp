//cisco packet tracer
#include <iostream>
#include <string>
#include <vector>
#include <limits>

void Ip_checker(std::string *return_ip);


//every device will have similar function 
class device
{
    private:
    std::string ip,status;
    int ports;
    std::string name,type;
    bool conneckted = false;
    public:
    
    device(std::string ip = "", int ports = 1, std::string name = "", std::string type = "", std::string status = "shutdown")
        : ip(ip), ports(ports), name(name), type(type), status(status) {}

    void ShowIP()
    {
        std::cout << "192.168.0.1";
    }
    virtual void ShowInfo()
    {
        std::cout << "Showed";
    }



    void Set_IP(std::string ip){this->ip = ip;}
    std::string Get_IP(){return ip;}
    void Set_Ports(int ports){this->ports = ports;}
    int Get_Ports(){return ports;}
    void Set_name(std::string name){this->name = name;}
    std::string Get_name(){return name;} 
    void Set_type(std::string type){this->type = type;}
    std::string Get_type(){return type;}
    void Set_status(std::string status){this->status = status;}
    std::string Get_status(){return status;}
    ~device() 
    {

    }
};
class router : public device
{
    public:
        using device::device;

        void ShowInfo() override
        {
            std::cout << "IP: " << Get_IP() << "\nPorts: " << Get_Ports() << "\nName: " << Get_name();
        }
};
class pc : public device
{
    public:
        using device::device;

        void ShowInfo() override
        {
            std::cout << "IP: " << Get_IP() << "\nPorts: " << Get_Ports() << "\nName: " << Get_name();
        }
};
class switch_ : public device
{
    public:
        using device::device;

        void ShowInfo() override
        {
            std::cout << "IP: " << Get_IP() << "\nPorts: " << Get_Ports() << "\nName: " << Get_name();
        }
};
class hub : public device
{
    public:
        using device::device;

        void ShowInfo() override
        {
            std::cout << "IP: " << Get_IP() << "\nPorts: " << Get_Ports() << "\nName: " << Get_name();
        }
};
class server : public device
{
    public:
        using device::device;

        void ShowInfo() override
        {
            std::cout << "IP: " << Get_IP() << "\nPorts: " << Get_Ports() << "\nName: " << Get_name();
        }
};
void clear()
{
    system("clear");
}

void Asking(std::vector <device*>& devises_array,int &devices);

void Interface(std::vector <device*>& devises_array,int &devices)
{
    std::cout << "You have " << devices << " devices" << std::endl;
    int router_county = 0,pc_county = 0,switch_county = 0,hub_county = 0,server_county = 0;
    ////////////////////Router////////////////////////////////////
    
    std::cout << "Router: " << std::endl;
    for (int i = 0; i < devises_array.size(); i++)
    {
        if(devises_array[i]->Get_type() == "router")
            {
                router_county++;
                std::cout << " \t"<< router_county <<"\t\tIP: " <<devises_array[i]->Get_IP() 
                << "\t\tPorts: " << devises_array[i]->Get_Ports()
                << "\tName: " << devises_array[i]->Get_name() << "\tStatus: " << devises_array[i]->Get_status() << std::endl; 
            }
    }

    //////////////////////////PC//////////////////////////////////////

    std::cout << "PC: " << std::endl;
    for (int i = 0; i < devises_array.size(); i++)
    {
        if(devises_array[i]->Get_type() == "pc")
            {
                pc_county++;
                std::cout << " \t"<< pc_county <<"\t\tIP: " <<devises_array[i]->Get_IP() 
                << "\t\tPorts: " << devises_array[i]->Get_Ports()
                << "\tName: " << devises_array[i]->Get_name() << std::endl;
            }
    }

    ///////////////////////Switch//////////////////////

    std::cout << "Switch: " << std::endl;
    for (int i = 0; i < devises_array.size(); i++)
    {
        if(devises_array[i]->Get_type() == "switch")
            {
                switch_county++;
                std::cout << " \t"<< switch_county <<"\t\tIP: " <<devises_array[i]->Get_IP() 
                << "\t\tPorts: " << devises_array[i]->Get_Ports()
                << "\tName: " << devises_array[i]->Get_name() << std::endl;
            }
    }

    ////////////////////Hub//////////////////////////////////////

    std::cout << "Hub: " << std::endl;
    for (int i = 0; i < devises_array.size(); i++)
    {
        if(devises_array[i]->Get_type() == "hub")
            {
                hub_county++;
                std::cout << " \t"<< hub_county <<"\t\tIP: " <<devises_array[i]->Get_IP() 
                << "\t\tPorts: " << devises_array[i]->Get_Ports()
                << "\tName: " << devises_array[i]->Get_name() << std::endl;
            }
    }

    //////////////////////////Server//////////////////////////////////

    std::cout << "Server: " << std::endl;
    for (int i = 0; i < devises_array.size(); i++)
    {
        if(devises_array[i]->Get_type() == "server")
            {
                server_county++;
                std::cout << " \t"<< server_county <<"\t\tIP: " <<devises_array[i]->Get_IP() 
                << "\t\tPorts: " << devises_array[i]->Get_Ports()
                << "\tName: " << devises_array[i]->Get_name() << std::endl;
            }        
    }
    //!!!!!!!!!!!!!!!!!!!!!Asking(devises_array,devices);!!!!!!!!!!!!!!!!!!!!!!!!
    //adding new name for int in for
}

void Asking(std::vector <device*>& devises_array,int &devices);

void Add_device(std::vector <device*>& devises_array,int &devices,std::string type)
{
    clear();
    int ports = 1;
    std::string ip,name;
    devices++;
    bool avaible_ports = (type == "router" || type == "switch" || type == "hub" || type == "server");
    bool active_ip = (type == "router" || type == "pc" || type == "hub" || type == "server");
    if (active_ip)
    {
        Ip_checker(&ip);
    }
    if(avaible_ports)
    {
        std::cout << "Enter ports: ";
        std::cin >> ports;
    }
    std::cout << "Enter name: ";
    std::cin >> name; 
    if(type == "router"){devises_array.push_back(new router(ip,ports,name,"router"));}
    else if(type == "pc"){devises_array.push_back(new pc(ip,ports,name,"pc"));}
    else if(type == "switch"){devises_array.push_back(new switch_(ip,ports,name,"switch"));}
    else if(type == "hub"){devises_array.push_back(new hub(ip,ports,name,"hub"));}
    else if(type == "server"){devises_array.push_back(new server(ip,ports,name,"server"));}
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    Asking(devises_array,devices);
}

void Asking(std::vector <device*>& devises_array,int &devices)
{
    std::string check;
    clear();
    Interface(devises_array,devices); 
    //std::cout << "Do you want to add something?(y/n)";
    //std::cin >> check;
    //clear();
    //if(check == "n" || check == "N")
    //{
    //   std::cout << "End!";
    //}
    //if(check == "Y" || check == "y")
    //{
        //int choice;
        std::string cmd,word1,word2;
        std::string type;
        int space_counter = 0;
        std::cout << "Devices: " << std::endl;
        std::cout << "[1] - Router" << std::endl;
        std::cout << "[2] - PC" << std::endl;
        std::cout << "[3] - Switch" << std::endl;
        std::cout << "[4] - Hub" << std::endl;
        std::cout << "[5] - Server" << std::endl;
        //std::cin.ignore();
               
        std::cout << ">";std::getline(std::cin,cmd);
        for(int i = 0;i < cmd.length();i++){
            if(cmd[i] == ' '){space_counter++;}
        }
        //std::clog << space_counter;
        if(space_counter == 1){
        size_t space = cmd.find(' ');
        if(space != std::string::npos){
            word1 = cmd.substr(0,space);
            word2 = cmd.substr(space + 1);
        }
        //std::cout << word1 << " " << word2;
        }
        if(word1 == "add")
        {
        if(word2 == "router"){type = "router";}
        if(word2 == "pc"){type = "pc";}
        if(word2 == "switch"){type = "switch";}
        if(word2 == "hub"){type = "hub";}
        if(word2 == "server"){type = "server";}
        Add_device(devises_array,devices,type);
        }else std::cout << "Error";
        if(word1 == "enter")
        {
            for (int i = 0; i < devises_array.size(); i++)
            {
                if(word2 == devises_array[i]->Get_name())
                {
                    clear();
                    std::cout << "Changer: ";
                    std::string device_changer;
                    std::cout << ">";std::cin >> device_changer;
                    if(device_changer == "ip")
                    {
                        std::string ip;
                        Ip_checker(&ip);
                        devises_array[i]->Set_IP(ip); 
                        Interface(devises_array,devices);
                    }
                    if(device_changer == "ports")
                    {
                        int ports;
                        std::cin >> ports;
                        devises_array[i]->Set_Ports(ports);
                        Interface(devises_array,devices); 
                    }
                    if(device_changer == "name")
                    {
                        std::string name;
                        std::cin >> name;
                        devises_array[i]->Set_name(name);
                        Interface(devises_array,devices); 
                    }
                    if(device_changer == "status")
                    {
                        std::string status;
                        std::cin >> status;
                        devises_array[i]->Set_status(status);
                        Interface(devises_array,devices); 
                    }
                }
            }
            
        }
        
        
  
    
    /*else 
    {
        std::cout << "Try again";
    }*/
}


void Ip_checker(std::string *return_ip)
{
    int point_counter = 0;
    int number_counter = 0;
    int ip_checker = 0;
    int ip_true = 0;
    std::string ip;
    char check;
    std::cout << "Enter ip: ";
    std::cin >> ip;
    for(int i = 0; i < ip.size();i++)
    {
        check = ip[i];
        if (check == '.')
        {
            if(number_counter <= 3 && number_counter >= 1 && (ip_checker == 0 || ip_checker == 1))
            {
                ip_checker++;
                number_counter = 0;
                ip_true++;
            }
            if(number_counter <= 2 && number_counter >= 1 && (ip_checker == 2 || ip_checker == 3))
            {
                ip_checker++;
                number_counter = 0;
                ip_true++;
                
            }
            
            
            
            point_counter++;
        }
        //add logic
        if((ip[i-1] != '.' && ip [i] != '.' && ip [i+1] != '.') ||
        (ip [i-1] != '.' && ip [i] != '.') || (ip [i] != '.' && ip [i+1] != '.') 
        || (ip[i-1] == '.' && ip[i] != '.' && ip[i+1] == '.'))
        {
            number_counter++;
        
            
        }
    }
        if(ip_true != 3)
        {
            std::string ip_2 = *return_ip;
            std::cout << "Error entering ip\n";
            Ip_checker(&ip_2);
        }
        if (ip_true == 3)
        {
            *return_ip = ip;
           
        }
        
}
int main()
{
    std::vector <device*> devises_array;
    int devices = 0;
    Asking(devises_array,devices);
  
    






    //for (int i = 0; i < devices; i++)
    //{
    //devises_array[i]->ShowInfo();
    //}
    
    

    for (int i = 0; i < devices; i++)
    {
    delete devises_array[i];
    }
    
    //std::cout << choice;
}
//add posibility to add other devices +
//add ip cheker +
//add liste of devices +
//add ability to connect wirelles devices
    //add status +
    //add change all for device (name) +
    // try to connect wirelles devices
//try to add saving to file  






