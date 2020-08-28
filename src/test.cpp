#include <cstdio>
#include <logger.hpp>
#include <vector>

auto main() -> int
{
    makedump::logger logger { makedump::logger::format("{white+} |", "HEADER") };
    // makedump::logger logger{ "", "..." };
    // makedump::logger logger{};
    logger.enable_debug();

    logger.print("One string: test 1");
    logger.print("test 2");
    logger.println("test 3");

    logger.print("Value: {:.2}", 13.14);
    logger.println("Register: {green+:2x}", 14);
    logger.println("{red:04} {green:4x} {blue:08}", 11, 0x22, 33);
    logger.println("Test {magenta+} test", makedump::logger::format("begin {:X} end", 0xF00D));

    string str { "+++" };
    logger.println("string&: {}", str);
    logger.println("char: {}", '*');
    logger.println("pointer: {yellow}", (uint8_t*)str.data());

    logger.println("Unicode String: {yellow}", L"WCHAR test");
    wchar_t test[] = L"WCHAR test";
    auto test_ptr = test;
    logger.println("Unicode String Pointer: {yellow:p}", test_ptr);

    auto arr = std::vector<uint16_t> { 1, 2, 3, 4 };
    logger.println("Array Pointer: {green} Size: {blue}", arr.data(), arr.size());
    logger.print("Array Items:");
    for (auto item : arr)
        logger.print("{green}", item);
    logger.println("");

    return EXIT_SUCCESS;
}
