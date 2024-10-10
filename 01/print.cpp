#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <iterator>
#include <ranges>
#include <numeric>
#include <cassert>

/**
 * 
 */
bool is_palindrome(const std::vector<int>& v)
{
    auto l = v | std::views::take(v.size()/2);
    auto r = v | std::views::reverse
               | std::views::take(v.size()/2);
    return std::ranges::equal(l, r);
}

/**
 * Add unit-test for triangle 
 */
void check_properties(
    const std::vector<std::vector<int>>& triangle
)
{
    size_t row_number = 1;
    int expected_total = 1;
    auto negative = [](int x){return x < 0;};
    // check the row number, first and last element is 1 
    // check the sum result match expectation
    for (const auto & row : triangle)
    {
        assert(row.front() ==1);
        assert(row.back() ==1);
        assert(row.size() == row_number++);
        assert(std::accumulate(row.begin(), row.end(), 0) == expected_total);
        expected_total *= 2; 
        auto negatives = row | std::views::filter(negative);
        assert(negatives.empty());
        assert(is_palindrome(row) == true);
    }
}


/**
 * Template for customized display 
 */
template<typename T>
std::ostream& operator << (std::ostream & s, 
   const std::vector<std::vector<T>>& triangle)
{
    for (const auto& row: triangle)
    {
        std::ranges::copy(row, std::ostream_iterator<T>(s, " "));
        s<<'\n';
    }
    return s;
}

/**
 * generate next vector<int> based on the input
 * next row[idx] = previous row[idx] + previous row[idx+1]
 * the next row[0] and next row[len(next row)-1] are all 1 
 */
auto get_next_row(const std::vector<int> & last_row)
{
    std::vector<int> next_row{1};
    if (last_row.empty())
    {
        return next_row;
    }
    for (size_t idx = 0; idx +1 < last_row.size(); idx++)
    {
        next_row.emplace_back(last_row[idx]+last_row[idx+1]);
    }
    next_row.emplace_back(1);
    return next_row;
}

/**
 * use move for efficiency, avoiding temperate variables copying 
 */
auto generate_triangle(int rows)
{
    std::vector<std::vector<int>> triangle{ {1}};
    for (int row= 1 ; row < rows; row++)
    {
        triangle.emplace_back(get_next_row(triangle.back()));
    }
    return triangle;
}

/**
 * main function 
 */
auto main() -> int {
    // row = 35 will cause int overflow 
    auto triangle = generate_triangle(5);
    check_properties(triangle);
    std::cout<<triangle;
    return 0 ;
}