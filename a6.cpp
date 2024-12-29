#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

// -------------------------- 1. Smart Grid --------------------------

// Class to simulate Smart Grids, handling energy distribution and consumption tracking
class SmartGrid {
public:
    unordered_map<int, double> energyConsumption;  // Consumer ID and energy consumption in kWh

    // Function to track energy consumption
    void track_consumption(int consumerID, double consumption) {
        energyConsumption[consumerID] = consumption;
        cout << "Energy consumption for Consumer " << consumerID << " is " << consumption << " kWh." << endl;
    }

    // Function to calculate the total energy consumption of all consumers
    double total_consumption() {
        double total = 0;
        for (const auto& entry : energyConsumption) {
            total += entry.second;
        }
        return total;
    }

    // Function to simulate energy distribution based on consumption
    void distribute_energy() {
        cout << "\nDistributing energy based on consumption:\n";
        for (const auto& entry : energyConsumption) {
            cout << "Consumer " << entry.first << " is using " << entry.second << " kWh of energy.\n";
        }
    }

    // Function to simulate energy savings from efficient grid management
    void energy_savings(double savings) {
        cout << "Energy savings achieved through smart grid management: " << savings << " kWh\n";
    }
};

// -------------------------- 2. Water Management System --------------------------

// Class to simulate Water Management Systems
class WaterManagementSystem {
public:
    unordered_map<int, double> waterConsumption;  // Consumer ID and water consumption in liters
    unordered_map<int, double> waterLevel;  // Water reservoir levels

    // Function to track water consumption
    void track_water_consumption(int consumerID, double consumption) {
        waterConsumption[consumerID] = consumption;
        cout << "Water consumption for Consumer " << consumerID << " is " << consumption << " liters." << endl;
    }

    // Function to monitor and reduce water wastage
    void monitor_water_wastage() {
        cout << "\nMonitoring Water Wastage:\n";
        for (const auto& entry : waterConsumption) {
            if (entry.second > 500) {  // Assuming 500 liters as the threshold for wastage
                cout << "Warning! Consumer " << entry.first << " is using excessive water: " << entry.second << " liters.\n";
            }
        }
    }

    // Function to simulate water conservation efforts
    void water_conservation(double conservation) {
        cout << "Water conservation achieved: " << conservation << " liters saved.\n";
    }

    // Function to check and update water reservoir levels
    void update_water_level(int reservoirID, double level) {
        waterLevel[reservoirID] = level;
        cout << "Updated water level for Reservoir " << reservoirID << ": " << level << " liters.\n";
    }
};

// -------------------------- 3. Renewable Energy Integration --------------------------

// Class to simulate renewable energy integration (solar, wind, etc.)
class RenewableEnergy {
public:
    double solarEnergyGenerated;  // Solar energy generated in kWh
    double windEnergyGenerated;   // Wind energy generated in kWh

    // Function to generate energy from solar and wind
    void generate_energy(double solarEnergy, double windEnergy) {
        solarEnergyGenerated = solarEnergy;
        windEnergyGenerated = windEnergy;
        cout << "\nEnergy generated from Solar: " << solarEnergy << " kWh\n";
        cout << "Energy generated from Wind: " << windEnergy << " kWh\n";
    }

    // Function to integrate renewable energy into the grid
    void integrate_energy(SmartGrid& smartGrid) {
        double totalRenewableEnergy = solarEnergyGenerated + windEnergyGenerated;
        cout << "\nIntegrating " << totalRenewableEnergy << " kWh of renewable energy into the Smart Grid.\n";

        // Distribute renewable energy to consumers
        double energyPerConsumer = totalRenewableEnergy / smartGrid.energyConsumption.size();
        for (const auto& entry : smartGrid.energyConsumption) {
            cout << "Distributing " << energyPerConsumer << " kWh of renewable energy to Consumer " << entry.first << ".\n";
        }
    }

    // Function to track total renewable energy contribution
    double total_renewable_energy() {
        return solarEnergyGenerated + windEnergyGenerated;
    }
};

// --------------------------- Main Program ---------------------------

int main() {
    // ------------------------ 1. Smart Grid -------------------------
    SmartGrid smartGrid;
    smartGrid.track_consumption(1, 100);  // Consumer 1 consumes 100 kWh
    smartGrid.track_consumption(2, 200);  // Consumer 2 consumes 200 kWh
    smartGrid.track_consumption(3, 150);  // Consumer 3 consumes 150 kWh

    // Distribute energy and calculate total consumption
    smartGrid.distribute_energy();
    cout << "\nTotal Energy Consumption: " << smartGrid.total_consumption() << " kWh.\n";

    // Smart grid energy savings
    smartGrid.energy_savings(50.0);  // Savings of 50 kWh

    // ------------------------ 2. Water Management System -------------------------
    WaterManagementSystem waterManagement;
    waterManagement.track_water_consumption(1, 400);  // Consumer 1 uses 400 liters
    waterManagement.track_water_consumption(2, 600);  // Consumer 2 uses 600 liters
    waterManagement.track_water_consumption(3, 300);  // Consumer 3 uses 300 liters

    // Monitor water wastage
    waterManagement.monitor_water_wastage();

    // Simulate water conservation efforts
    waterManagement.water_conservation(100.0);  // 100 liters saved

    // Update water reservoir levels
    waterManagement.update_water_level(1, 10000.0);  // Reservoir 1 level 10000 liters

    // ------------------------ 3. Renewable Energy Integration -------------------------
    RenewableEnergy renewableEnergy;
    renewableEnergy.generate_energy(500, 200);  // Generate 500 kWh from solar and 200 kWh from wind

    // Integrate renewable energy into the smart grid
    renewableEnergy.integrate_energy(smartGrid);

    // Display total renewable energy contribution
    cout << "\nTotal Renewable Energy: " << renewableEnergy.total_renewable_energy() << " kWh.\n";

    return 0;
}

