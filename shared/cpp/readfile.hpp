#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <optional>

std::vector<std::pair<std::vector<int>, std::vector<int>>> parseFile(const std::string& filename);
