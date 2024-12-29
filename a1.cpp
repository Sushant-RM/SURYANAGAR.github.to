#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// ------------------------ 1. Geospatial Mapping and GIS ------------------------

class GIS {
public:
    // Add a land use zone to the GIS system
    void add_land_use_zone(const string& zone_name, const string& zone_type, double area) {
        land_use_zones[zone_name] = {zone_type, area};
    }

    // Display all land use zones and their details
    void display_land_use_zones() {
        cout << "\nLand Use Zones: " << endl;
        for (const auto& zone : land_use_zones) {
            cout << "Zone: " << zone.first << ", Type: " << zone.second.type
                 << ", Area: " << zone.second.area << " sqm" << endl;
        }
    }

private:
    struct LandUseZone {
        string type; // Residential, Commercial, Industrial, etc.
        double area; // Area of the zone in square meters
    };

    unordered_map<string, LandUseZone> land_use_zones;  // Maps zone names to their properties
};

// ------------------------ 2. Digital Twins ------------------------

class DigitalTwin {
public:
    // Create a virtual model for the city
    void create_model(const string& city_name) {
        city_model = "Virtual Model for " + city_name;
        cout << "Digital Twin model created for: " << city_name << endl;
    }

    // Simulate a scenario in the city model (e.g., traffic congestion, urban sprawl)
    void simulate_scenario(const string& scenario) {
        cout << "Simulating scenario: " << scenario << endl;
        // Basic simulation example
        if (scenario == "traffic congestion") {
            cout << "Optimizing road network to alleviate congestion..." << endl;
        }
        else if (scenario == "urban sprawl") {
            cout << "Recommending more residential areas and parks..." << endl;
        }
    }

    // Display the digital twin model for visualization
    void display_model() {
        cout << "Displaying Digital Twin model: " << city_model << endl;
    }

private:
    string city_model;  // Store the virtual model of the city
};

// ------------------------ 3. Participatory Planning Tools ------------------------

class ParticipatoryPlanning {
public:
    // Collect feedback from citizens regarding city projects and policies
    void collect_feedback(const string& citizen_name, const string& feedback) {
        feedback_queue.push({citizen_name, feedback});
    }

    // Display all collected feedback in priority order (alphabetically by citizen name)
    void display_feedback() {
        cout << "\nCitizen Feedback: " << endl;
        while (!feedback_queue.empty()) {
            auto feedback = feedback_queue.top();
            feedback_queue.pop();
            cout << "Citizen: " << feedback.citizen_name << " | Feedback: " << feedback.feedback_text << endl;
        }
    }

private:
    struct Feedback {
        string citizen_name;
        string feedback_text;
    };

    // Comparator to sort feedback alphabetically by citizen name
    struct FeedbackComparator {
        bool operator()(const Feedback& f1, const Feedback& f2) {
            return f1.citizen_name > f2.citizen_name;
        }
    };

    priority_queue<Feedback, vector<Feedback>, FeedbackComparator> feedback_queue;  // Priority queue to store feedback
};

// ------------------------ 4. Urban Planning System ------------------------

class UrbanPlanningSystem {
public:
    UrbanPlanningSystem() {
        cout << "Urban Planning System Initialized!" << endl;
    }

    // Setup geospatial mapping with land use zones
    void setup_geospatial_mapping() {
        gis.add_land_use_zone("Downtown", "Commercial", 5000);
        gis.add_land_use_zone("Old Town", "Residential", 7000);
        gis.add_land_use_zone("Tech Park", "Industrial", 10000);
        gis.display_land_use_zones();
    }

    // Create a digital twin model for the city
    void create_digital_twin(const string& city_name) {
        digital_twin.create_model(city_name);
        digital_twin.display_model();
    }

    // Simulate an urban planning scenario (e.g., traffic congestion, urban sprawl)
    void simulate_urban_scenario(const string& scenario) {
        digital_twin.simulate_scenario(scenario);
    }

    // Gather feedback from citizens on city projects and policies
    void gather_citizen_feedback() {
        participatory_planning.collect_feedback("Alice", "More parks and green spaces in the city.");
        participatory_planning.collect_feedback("Bob", "Improve public transportation services.");
        participatory_planning.collect_feedback("Charlie", "Create more cycling lanes in downtown.");
        participatory_planning.display_feedback();
    }

private:
    GIS gis;                 // Geospatial Mapping and GIS
    DigitalTwin digital_twin; // Digital Twin model for urban design simulation
    ParticipatoryPlanning participatory_planning; // Citizen feedback collection
};

// ------------------------ Main Function ------------------------

int main() {
    // Initialize Urban Planning System
    UrbanPlanningSystem ups;

    // 1. Setup Geospatial Mapping and GIS
    ups.setup_geospatial_mapping();

    // 2. Create Digital Twin model for a city
    ups.create_digital_twin("Sample City");

    // 3. Simulate urban planning scenarios
    ups.simulate_urban_scenario("traffic congestion");
    ups.simulate_urban_scenario("urban sprawl");

    // 4. Collect and display citizen feedback
    ups.gather_citizen_feedback();

    return 0;
}
