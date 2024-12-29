#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// ------------------------- 1. E-Governance Platform ---------------------------

// Class to simulate the e-Governance Platform, handling grievances, requests, and decisions
class EGovernancePlatform {
public:
    unordered_map<int, string> grievances;  // Map of grievance IDs to descriptions
    unordered_map<int, string> serviceRequests;  // Map of request IDs to service descriptions

    // Function to submit a grievance
    void submit_grievance(int grievanceID, const string& description) {
        grievances[grievanceID] = description;
        cout << "Grievance " << grievanceID << " submitted: " << description << endl;
    }

    // Function to submit a service request
    void submit_service_request(int requestID, const string& serviceDescription) {
        serviceRequests[requestID] = serviceDescription;
        cout << "Service Request " << requestID << " submitted: " << serviceDescription << endl;
    }

    // Function to view all grievances
    void view_grievances() {
        cout << "\nGrievances List:\n";
        for (const auto& grievance : grievances) {
            cout << "ID: " << grievance.first << " - Description: " << grievance.second << endl;
        }
    }

    // Function to view all service requests
    void view_service_requests() {
        cout << "\nService Requests List:\n";
        for (const auto& request : serviceRequests) {
            cout << "ID: " << request.first << " - Description: " << request.second << endl;
        }
    }

    // Function for public participation in decision-making
    void participate_in_decision(const string& feedback) {
        cout << "\nPublic Feedback: " << feedback << endl;
    }
};

// ------------------------- 2. Open Data Initiative ---------------------------

// Class to simulate the Open Data Initiative, sharing urban data
class OpenDataInitiative {
public:
    unordered_map<string, double> urbanData;  // Data on various urban metrics

    // Function to add or update urban data
    void update_data(const string& metric, double value) {
        urbanData[metric] = value;
        cout << "Updated " << metric << ": " << value << endl;
    }

    // Function to view urban data
    void view_data() {
        cout << "\nUrban Data:\n";
        for (const auto& data : urbanData) {
            cout << data.first << ": " << data.second << endl;
        }
    }
};

// ------------------------- 3. AI-Powered Policy Design ---------------------------

// Class to simulate AI-Powered Policy Design, using data to create policies
class AIPoweredPolicyDesign {
public:
    // Function to analyze urban data and create a policy based on data trends
    void analyze_and_create_policy(const unordered_map<string, double>& urbanData) {
        cout << "\nAI-Powered Policy Design: Analyzing Data to Create Policies\n";

        // Simple analysis: identify high priority metrics (e.g., pollution or traffic congestion)
        if (urbanData.at("Air Quality") < 50.0) {
            cout << "Policy Suggestion: Improve air quality by enforcing stricter emissions standards.\n";
        }
        if (urbanData.at("Traffic Congestion") > 80.0) {
            cout << "Policy Suggestion: Implement better public transport solutions and reduce car usage.\n";
        }
        if (urbanData.at("Waste Management") < 60.0) {
            cout << "Policy Suggestion: Improve waste management systems and recycling programs.\n";
        }
    }
};

// --------------------------- Main Program -----------------------------

int main() {
    // ------------------------- E-Governance Platform -------------------------
    EGovernancePlatform egovernance;
    egovernance.submit_grievance(101, "Pothole on Main Street");
    egovernance.submit_service_request(201, "Need more street lights on Elm Avenue");
    egovernance.view_grievances();
    egovernance.view_service_requests();
    egovernance.participate_in_decision("I suggest adding more green spaces in the city.");

    // ------------------------- Open Data Initiative -------------------------
    OpenDataInitiative openData;
    openData.update_data("Air Quality", 45.0);  // Air Quality index (lower is better)
    openData.update_data("Traffic Congestion", 85.0);  // Higher value means worse congestion
    openData.update_data("Waste Management", 50.0);  // Waste management efficiency (0-100)
    openData.view_data();

    // ------------------------- AI-Powered Policy Design -------------------------
    AIPoweredPolicyDesign aiPolicy;
    aiPolicy.analyze_and_create_policy(openData.urbanData);

    return 0;
}
