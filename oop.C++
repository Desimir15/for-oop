
#include <iostream>
#include <string>
using namespace std;


class PublicInstitution {
protected:
    string name;
    string address;

public:
    virtual ~PublicInstitution() {}
    PublicInstitution() : name("name"), address("address") {}
    PublicInstitution(const string name, const string address = "address")
        : name(name), address(address) {
    }

    virtual void printInfo() const = 0;

    void announce() const {
        cout << "Public institution " << name << " is at: " << address << endl;
    }

    virtual void customCall() = 0;
};

class GovernmentBody : public PublicInstitution {
protected:
    double budget;
    string leader;

public:
    GovernmentBody() : PublicInstitution(), budget(0.0), leader("leader") {}
    GovernmentBody( string name,  string address, double budget = 10000.0,  string leader = "leader")
        : PublicInstitution(name, address), budget(budget), leader(leader) {
    }

    virtual void approveBudget() {
        cout << name << " has approved a budget of " << budget << " BGN." << endl;
    }

    virtual void appointLeader() {
        cout << leader << " has been appointed as leader of " << name << "." << endl;
    }

    void printInfo() const override {
        cout << "Government Body 1: " << name << endl;
        cout<< " Address: " << address << endl;
        cout << " Budget: " << budget << endl;
        cout << " Leader: " << leader << endl;
    }

    void customCall() override {
        approveBudget();
        
    }
};


class Parliament : public GovernmentBody {
protected:
    int numberOfMembers;
    string type;

public:
    Parliament() : GovernmentBody(), numberOfMembers(0), type("no") {}
    Parliament(const string name, const string address, double budget, const string leader,
        int numberOfMembers, const string type = "National")
        : GovernmentBody(name, address, budget, leader), numberOfMembers(numberOfMembers), type(type) {
    }

    void debate() {
        cout << name << " is debating important issues." << endl;
    }

    void passLaw() {
        cout << name << " has passed a new law." << endl;
    }

    void printInfo() const override {
        cout << "Parliament: " << name << endl;
        cout << " Members: " << numberOfMembers << endl;
        cout <<" Type: " << type << endl;
        cout << " Budget: " << budget << endl;
         cout <<  " Leader: " << leader << endl;
    }

    void customCall() override {
        debate();
        passLaw();
    }
};

class ParliamentCommittee : public Parliament {
    string committeeName;
    int committeeMemberCount;

public:
    ParliamentCommittee() : Parliament(), committeeName(" Committee"), committeeMemberCount(0) {}

    ParliamentCommittee(const string name, const string address, double budget, const string leader,
        int numberOfMembers, const string committeeName, int committeeMemberCount)
        : Parliament(name, address, budget, leader, numberOfMembers, "Committee"),
        committeeName(committeeName), committeeMemberCount(committeeMemberCount) {
    }

    void holdCommitteeMeeting() {
        cout << committeeName << " of " << name << " is holding a committee meeting with "
            << committeeMemberCount << " members." << endl;
    }

    void printInfo() const override {
        cout << "Parliament Committee: " << name << endl;
        cout <<" Committee: " << committeeName << endl;
        cout << " Committee Members: " << committeeMemberCount << endl;
        cout << " Parliament Members: " << numberOfMembers << endl;
        cout <<" Leader: " << leader << endl;
    }

    void customCall() override {
        holdCommitteeMeeting();
    }
};


class ParliamentOffice : public Parliament {
    string officeLocation;
    int staffCount;

public:
    ParliamentOffice() : Parliament(), officeLocation(" Office"), staffCount(0) {}

    ParliamentOffice(const string name, const string address, double budget, const string leader,
        int numberOfMembers, const string& officeLocation, int staffCount)
        : Parliament(name, address, budget, leader, numberOfMembers, "Office"),
        officeLocation(officeLocation), staffCount(staffCount) {
    }

    void manageOffice() {
        cout << "Parliament Office at " << officeLocation << endl;
         cout<<" staff "<< staffCount << " staff members." << endl;
    }

    void printInfo() const override {
        cout << "Parliament Office: " << name << endl;
        cout << " Location: " << officeLocation << endl;
        cout << " Staff Count: " << staffCount << endl;
        cout << " Parliament Members: " << numberOfMembers << endl;
        cout << " Leader: " << leader << endl;
    }

    void customCall() override {
        manageOffice();
    }
};


class MunicipalBody : public PublicInstitution {
protected:
    int population;
    string mayor;

public:
    MunicipalBody() : PublicInstitution(), population(0), mayor("mayor") {}
    MunicipalBody(const string& name, const string& address, int population, const string& mayor)
        : PublicInstitution(name, address), population(population), mayor(mayor) {
    }

    void holdMunicipalMeeting() {
        cout << name << " is holding a municipal meeting." << endl;
    }

    void mayorAddress() {
        cout << "Mayor " << mayor << " is addressing the citizens at " << name << "." << endl;
    }

    void printInfo() const override {
        cout << "Municipal Body: " << name << ", Address: " << address
            << ", Population: " << population << ", Mayor: " << mayor << endl;
    }

    void customCall() override {
        holdMunicipalMeeting();
        mayorAddress();
    }
};


class CityCouncil : public MunicipalBody {
protected:
    int councilMembers;
    string cityName;

public:
    CityCouncil() : MunicipalBody(), councilMembers(0), cityName("cityName") {}
    CityCouncil(const string name, const string address, int population, const string mayor,
        int councilMembers, const string& cityName)
        : MunicipalBody(name, address, population, mayor), councilMembers(councilMembers), cityName(cityName) {
    }

    void holdCouncilVote() {
        cout << "City Council of " << cityName << " is holding a vote with "
            << councilMembers << " members." << endl;
    }

    void organizeCityEvent() {
        cout << cityName << " City Council is organizing a community event." << endl;
    }

    void printInfo() const override {
        cout << "City Council: " << name << ", City: " << cityName
            << ", Council Members: " << councilMembers << ", Mayor: " << mayor
            << ", Population: " << population << endl;
    }

    void customCall() override {
        holdCouncilVote();
        organizeCityEvent();
    }
};

class CityDepartment : public CityCouncil {
    string departmentName;
    int staffCount;

public:
    CityDepartment() : CityCouncil(), departmentName(" Department"), staffCount(0) {}

    CityDepartment(const string name, const string address, int population, const string mayor,
        int councilMembers, const string cityName, const string departmentName, int staffCount)
        : CityCouncil(name, address, population, mayor, councilMembers, cityName),
        departmentName(departmentName), staffCount(staffCount) {
    }

    void conductInspections() {
        cout << departmentName << " in " << cityName << " is conducting inspections with "
            << staffCount << " staff members." << endl;
    }

    void printInfo() const override {
        cout << "City Department: " << name << ", Department: " << departmentName
            << ", Staff Count: " << staffCount << ", City: " << cityName
            << ", Mayor: " << mayor << endl;
    }

    void customCall() override {
        conductInspections();
    }
};


class CityOffice : public CityCouncil {
    string officeLocation;
    int staffCount;

public:
    CityOffice() : CityCouncil(), officeLocation(" Office"), staffCount(0) {}

    CityOffice(const string name, const string address, int population, const string mayor,
        int councilMembers, const string cityName, const string officeLocation, int staffCount)
        : CityCouncil(name, address, population, mayor, councilMembers, cityName),
        officeLocation(officeLocation), staffCount(staffCount) {
    }

    void manageDocuments() {
        cout << "City Office at " << officeLocation << " manages documents with "
            << staffCount << " staff members." << endl;
    }

    void printInfo() const override {
        cout << "City Office: " << name << ", Location: " << officeLocation
            << ", Staff Count: " << staffCount << ", City: " << cityName
            << ", Mayor: " << mayor << endl;
    }

    void customCall() override {
        manageDocuments();
    }
};


int main() {
    PublicInstitution* institutions[8] = {
    institutions[0] = new GovernmentBody("Ministry of Education ", "10 Gov St", 25692, "Anna Minister"),
     institutions[1] = new Parliament("National Parliament", "1 Parliament Sq", 15000, "John Speaker", 300, "National"),
     institutions[2] = new ParliamentCommittee("Finance Committee", "1 Parliament Sq", 30000, "Emma Chair", 50, "Finance Committee", 15),
     institutions[3] = new ParliamentOffice("Parliament Operations Office", "2 Parliament Sq", 10000, "Michael Admin", 40, "Main Office", 20),
     institutions[4] = new MunicipalBody("City Municipality", "123 Main St", 10000, "Olivia Mayor"),
     institutions[5] = new CityCouncil("City Council", "45 Council St", 8000, "James Mayor", 25, "Springfield"),
     institutions[6] = new CityDepartment("Health Department", "45 Council St", 80000, "James Mayor", 25, "Springfield", "Health Dept", 30),
    institutions[7] = new CityOffice("City Records Office", "50 City Hall", 80000, "James Mayor", 25, "Springfield", "Records Office", 40)
    };
    
 
    for (int i = 0; i < 8; ++i) {
        cout << "\n" << endl;
        institutions[i]->printInfo();
        institutions[i]->announce();
        institutions[i]->customCall();
    }

    return 0;
}
