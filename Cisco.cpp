//cisco packet tracer
#include <iostream>
#include <string>
#include <vector>


void Ip_checker(std::string *return_ip);


//every device will have similar function 
class device
{
    private:
    std::string ip;
    int ports;
    std::string name,type;
    bool conneckted = false;
    public:
    
    device(std::string ip, int ports, std::string name)
    : ip(ip), ports(ports), name(name) {

    }

    device(std::string ip,int ports)
    : ip(ip), ports(ports) , name(""){
        
    }
    device(std::string ip)
    : ip(ip) , ports(0) , name("")
    {
        
    }
    device() : ip("") , ports (0) , name ("")
    {

    }
    device(std::string ip,int ports,std::string name,std::string type) : ip(ip), ports(ports), name (name),type(type)
        {

        }

    void ShowIP()
    {
        std::cout << "192.168.0.1";
    }
    virtual void ShowInfo()
    {
        std::cout << "Showed";
    }



    void Set_IP(std::string ip)
    {
        this -> ip = ip;
    }
    std::string Get_IP()
    {
        return this -> ip;
    }
    void Set_Ports(int ports)
    {
        this -> ports = ports;
    }
    int Get_Ports()
    {
        return this -> ports; 
    }
    void Set_name(std::string name)
    {
        this -> name = name;
    }
    std::string Get_name()
    {
        return this -> name;
    } 
    std::string Get_type()
    {
        return type;
    }
    void Set_type(std::string type)
    {
        this -> type = type;
    }
    ~device() 
    {

    }
};
class router : public device
{
    public:
        router()
        {

        }
        router(std::string ip,int ports) : device(ip, ports)
        {
           
        }
        router(std::string ip,int ports,std::string name) : device(ip, ports, name)
        {

        }
        router(std::string ip,int ports,std::string name,std::string type) : device(ip, ports, name ,type)
        {

        }
        ~router()
        {

        }

        void ShowInfo() override
        {
            std::cout << "IP: " << Get_IP() << "\nPorts: " << Get_Ports() << "\nName: " << Get_name();
        }



};
class pc : public device
{
    private:

    public:
        pc() 
        {

        }
        pc(std::string ip,int ports) : device (ip,ports)
        {

        }
        pc(std::string ip,int ports,std::string name) : device(ip,ports,name)
        {

        }
        pc(std::string ip,int ports,std::string name,std::string type) : device (ip, ports, name ,type)
        {

        }
        ~pc()
        {
            
        }
        void ShowInfo() override
        {
            std::cout << "IP: " << Get_IP() << "\nPorts: " << Get_Ports() << "\nName: " << Get_name();
        }
};
class switch_ : public device
{

    private:

    public:
        switch_() 
        {

        }
        switch_(int ports,std::string name) : device (" ",ports,name)
        {

        }
        switch_(std::string name) : device("",8,name)
        {

        }
        switch_(int ports) : device("",ports,"SWITCH")
        {

        }
        switch_(std::string ip,int ports,std::string name) : device (ip,ports,name)
        {

        }
        switch_(std::string ip,int ports,std::string name,std::string type) : device (ip, ports, name ,type)
        {

        }
        ~switch_()
        {
            
        }
        void ShowInfo() override
        {
            std::cout << "IP: " << Get_IP() << "\nPorts: " << Get_Ports() << "\nName: " << Get_name();
        }
};
class hub : public device
{

    private:

    public:
        hub() 
        {

        }
        hub(std::string ip,int ports) : device (ip,ports)
        {

        }
        hub(std::string ip,int ports,std::string name) : device(ip,ports,name)
        {

        }
        hub(std::string ip,int ports,std::string name,std::string type) : device(ip, ports, name ,type)
        {

        }
        ~hub()
        {
            
        }
        void ShowInfo() override
        {
            std::cout << "IP: " << Get_IP() << "\nPorts: " << Get_Ports() << "\nName: " << Get_name();
        }
};
class server : public device
{

    private:

    public:
        server() 
        {

        }
        server(std::string ip,int ports) : device (ip,ports)
        {

        }
        server(std::string ip,int ports,std::string name) : device(ip,ports,name)
        {

        }
        server(std::string ip,int ports,std::string name,std::string type) : device(ip, ports, name ,type)
        {

        }
        ~server()
        {
            
        }
        void ShowInfo() override
        {
            std::cout << "IP: " << Get_IP() << "\nPorts: " << Get_Ports() << "\nName: " << Get_name();
        }
};

void Interface(std::vector <device*>& devises_array,int &devices)
{
    std::cout << "You have " << devices << " devices" << std::endl;
    
    ////////////////////Router////////////////////////////////////
    
    std::cout << "Router: " << std::endl;
    for (int i = 0; i < devises_array.size(); i++)
    {
        if(devises_array[i]->Get_type() == "router")
            {
                std::cout << " \t"<< i + 1 <<"\t\tIP: " <<devises_array[i]->Get_IP() 
                << "\t\tPorts: " << devises_array[i]->Get_Ports()
                << "\tName: " << devises_array[i]->Get_name() << std::endl; 
            }
    }

    //////////////////////////PC//////////////////////////////////////

    std::cout << "PC: " << std::endl;
    for (int i = 0; i < devises_array.size(); i++)
    {
        if(devises_array[i]->Get_type() == "pc")
            {
                std::cout << " \t"<< i + 1 <<"\t\tIP: " <<devises_array[i]->Get_IP() 
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
                std::cout << " \t"<< i + 1 <<"\t\tIP: " <<devises_array[i]->Get_IP() 
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
                std::cout << " \t"<< i + 1 <<"\t\tIP: " <<devises_array[i]->Get_IP() 
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
                std::cout << " \t"<< i + 1 <<"\t\tIP: " <<devises_array[i]->Get_IP() 
                << "\t\tPorts: " << devises_array[i]->Get_Ports()
                << "\tName: " << devises_array[i]->Get_name() << std::endl;
            }        
    }
    //adding new name for int in for
}

void Asking(std::vector <device*>& devises_array,int &devices);
void Add_device(std::vector <device*>& devises_array,int &devices,std::string type)
{
    system("clear");
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
    Asking(devises_array,devices);
}
void Asking(std::vector <device*>& devises_array,int &devices)
{
    std::string check;
    system("clear");
    Interface(devises_array,devices); 
    std::cout << "Do you want to add something?(y/n)";
    std::cin >> check;
    system("clear");
    if(check == "n" || check == "N")
    {
        std::cout << "End!";
    }
    if(check == "Y" || check == "y")
    {
        int choice;
        std::string type;
        std::cout << "Devices: " << std::endl;
        std::cout << "[1] - Router" << std::endl;
        std::cout << "[2] - PC" << std::endl;
        std::cout << "[3] - Switch" << std::endl;
        std::cout << "[4] - Hub" << std::endl;
        std::cout << "[5] - Server" << std::endl;
        std::cin >> choice;
        if(choice == 1){type = "router";}
        if(choice == 2){type = "pc";}
        if(choice == 3){type = "switch";}
        if(choice == 4){type = "hub";}
        if(choice == 5){type = "server";}
        Add_device(devises_array,devices,type);
        
  
    }
    else 
    {
        std::cout << "Try again";
    }
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
//add liste of devices
//add ability to connect wirelles devices
//try to add saving to file  






