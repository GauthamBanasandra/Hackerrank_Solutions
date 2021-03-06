cmake_minimum_required(VERSION 3.8)
project(Codeforces)

set(CMAKE_CXX_STANDARD 17)

find_package(Java REQUIRED)
include(UseJava)

# Compete
    # Round 540
    add_executable(Water_buying "Compete/Round 540/A/Water buying.cpp")
    add_executable(Tanya_and_candies "Compete/Round 540/B/Tanya and candies.cpp")
    # Round 548
    add_executable(Even_substrings "Compete/Round 548/A/Even substrings.cpp")
    add_executable(Chocolates "Compete/Round 548/B/Chocolates.cpp")
    # Round 549
    add_executable(Nirvana "Compete/Round 549/B/Nirvana.cpp")
    # Round 550
    add_executable(Diverse_strings "Compete/Round 550/A/Diverse strings.cpp")
    add_executable(Parity_alternated_deletions "Compete/Round 550/B/Parity alternated deletions.cpp")
    add_executable(Two_shuffled_sequences "Compete/Round 550/C/Two shuffled sequences.cpp")
    # Round 551
    add_executable(Serval_and_bus "Compete/Round 551/A/Serval and bus.cpp")
    add_executable(Serval_toy_bricks "Compete/Round 551/B/Serval and toy bricks.cpp")
    add_executable(Serval_and_parenthesis_sequence "Compete/Round 551/C/Serval and parenthesis sequence.cpp")
    # Round 552
    add_executable(Restoring_three_numbers "Compete/Round 552/A/Restoring three numbers.cpp")
    add_executable(Make_them_equal "Compete/Round 552/B/Make them equal.cpp")
    # Round 553
    add_executable(Maxim_and_biology "Compete/Round 553/A/Maxim and biology.cpp")
    add_executable(Dima_and_a_bad_xor "Compete/Round 553/B/Dima and a bad xor.cpp")
    # Round 554
    add_executable(Neko_finds_grapes "Compete/Round 554/A/Neko finds grapes.cpp")
    # Round 556
    add_executable(Stock_arbitraging "Compete/Round 556/A/Stock arbitraging.cpp")
    add_executable(Tiling_challenge "Compete/Round 556/B/Tiling challenge.cpp")
    # Edu round 64
    add_executable(Inscribed_figures "Compete/Edu round 64/A/Inscribed figures.cpp")
    # Round 558
    add_executable(Eating_soup "Compete/Round 558/A/Eating soup.cpp")
    add_executable(Cat_party_easy_edition "Compete/Round 558/B1/Cat party easy edition.cpp")
    # Round 559
    add_executable(A_pile_of_stones "Compete/Round 559/A/A pile of stones.cpp")
    add_executable(Expansion_coefficient_of_the_array "Compete/Round 559/B/Expansion coefficient of the array.cpp")
    # Round 562
    add_executable(Circle_metro "Compete/Round 562/A/Circle metro.cpp")

# Practice
    # Round 464
    add_executable(Love_triangle "Practice/Round 464/A/Love triangle.cpp")
    # Round 87
    add_executable(Party "Practice/Round 87/A/Party.cpp")
    # Round 368
    add_executable(Bakery "Practice/Round 368/B/Bakery.cpp")
    # Round 503
    add_jar(Badge "Practice/Round 503/B/src/Solution.java")
    # 8VC venture cup 2017 elimination round
    add_jar(PolandBall_and_forest "Practice/8VC venture cup 2017 elimination round/C/src/Solution.java")
    # Round 452
    add_executable(Dividing_the_numbers "Practice/Round 452/C/Dividing the numbers.cpp")
    # Round 295
    add_executable(Two_buttons "Practice/Round 295/B/Two buttons.cpp")
    # Round 435
    add_executable(Mahmoud_and_ehab_and_the_bipartiteness "Practice/Round 435/B/Mahmoud and ehab and the bipartiteness.cpp")
    # Edu round 65
    add_executable(News_distribution "Practice/Edu round 65/C/News distribution.cpp")
