//   OpenNN: Open Neural Networks Library
//   www.opennn.net
//
//   N O R M A L I Z E D   S Q U A R E D   E R R O R   T E S T   C L A S S   H E A D E R
//
//   Artificial Intelligence Techniques SL (Artelnics)                     
//   artelnics@artelnics.com

#ifndef NORMALIZEDSQUAREDERRORTEST_H
#define NORMALIZEDSQUAREDERRORTEST_H

// Unit testing includes

#include "../opennn/unit_testing.h"

class NormalizedSquaredErrorTest : public UnitTesting 
{

public:

   explicit NormalizedSquaredErrorTest(); 

   virtual ~NormalizedSquaredErrorTest();

   // Constructor and destructor methods

   void test_constructor();

   // Normalization coefficient

   void test_calculate_normalization_coefficient();

   // Back-propagation methods

   void test_back_propagate();

   void test_back_propagate_lm();

   void test_calculate_error();

   void test_calculate_error_gradient();

   // Unit testing methods

   void run_test_case();

private:

   Index samples_number;
   Index inputs_number;
   Index outputs_number;
   Index neurons_number;

   Tensor<Index, 1> training_samples_indices;
   Tensor<Index, 1> input_variables_indices;
   Tensor<Index, 1> target_variables_indices;

   DataSet data_set;

   NeuralNetwork neural_network;

   NormalizedSquaredError normalized_squared_error;

   DataSetBatch batch;

   NeuralNetworkForwardPropagation forward_propagation;

   LossIndexBackPropagation back_propagation;

   Tensor<type, 1> gradient_numerical_differentiation;
   Tensor<type, 2> jacobian_numerical_differentiation;
};


#endif


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2021 Artificial Intelligence Techniques SL.
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
