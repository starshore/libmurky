/*********************************************************************
 * Copyright (c) 2021-2022 STARSHORE. All rights reserved.
 *
 * @file   main.cpp
 * @brief  unittest entry
 *
 * @author starshore
 * @date   November 2022
 *********************************************************************/

#include <doctest/doctest.h>
#include <spdlog/spdlog.h>

using ctx = doctest::Context;

int main(int argc, char **argv)
{
    int status;
    ctx context;

    spdlog::info("Begin context.run...");
    status = context.run();
    spdlog::info("Testing completed!");

    return status;
}
