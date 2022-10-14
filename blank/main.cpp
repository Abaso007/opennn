//   OpenNN: Open Neural Networks Library
//   www.opennn.net
//
//   B L A N K   A P P L I C A T I O N
//
//   Artificial Intelligence Techniques SL
//   artelnics@artelnics.com

// System includes

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>

// OpenNN includes

#include "../opennn/opennn.h"
#include "../tests/genetic_algorithm_test.h"
using namespace opennn;

int main(int argc, char* argv[])
{
    try
    {
        cout << "Hello OpenNN!" << endl;

        //DataSet data_set("C:/Users/rodrigo ingelmo/Documents/opennn - genetic/opennn/opennn/blank/data/sum.csv", ';', false);
        try {
            
            DataSet data_set("D:/sum.csv", ';', false);
            try {
                Index input_variables_number = data_set.get_input_variables_number();
                cout << input_variables_number << endl;
                Index target_variables_number = data_set.get_target_variables_number();
                cout << target_variables_number << endl;

                const Index neurons_number = Index(0);
                cout << neurons_number << endl;
                NeuralNetwork neural_network(NeuralNetwork::ProjectType::Approximation, { input_variables_number, neurons_number, target_variables_number });

                neural_network.print();
                
                TrainingStrategy training_strategy(&neural_network, &data_set);
                training_strategy.set_optimization_method(TrainingStrategy::OptimizationMethod::ADAPTIVE_MOMENT_ESTIMATION);
                TrainingStrategy* training_strategy_pointer = &training_strategy;
                cout << "\n";
                training_strategy.print();
                try
                {
                    GeneticAlgorithmTest::UnitTesting;

                    //GeneticAlgorithm genetic_algorithm(training_strategy_pointer);

                    GeneticAlgorithm* genetic_algorithm_pointer = nullptr;
                    GeneticAlgorithm genetic_algorithm(training_strategy_pointer);
                    genetic_algorithm_pointer = &genetic_algorithm;
                    genetic_algorithm_pointer->check();
                    genetic_algorithm_pointer->set_initialization_method(GeneticAlgorithm::InitializationMethod::Correlations);
                    genetic_algorithm_pointer->initialize_population();
                    genetic_algorithm_pointer->print_population();

                    
                }
                catch (const exception& e)
                {
                    cerr << e.what() << endl;

                    return 1;
                }

                
            }catch (const exception& e)
            {
                cerr << e.what() << endl;

                return 1;
            }
                        
        }
        catch (const exception& e)
        {
            cerr << e.what() << endl;

            return 1;
        }
        
        cout << "Bye OpenNN!" << endl;
    }
    catch (const exception& e)
    {
        cerr << e.what() << endl;

        return 1;
    }
}

// OpenNN: Open Neural Networks Library.
// Copyright (C) Artificial Intelligence Techniques SL.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

