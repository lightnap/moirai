#include <catch2/catch_test_macros.hpp>

#include <layers/c_data_layer.hpp>
#include <node/c_node.hpp>

#include <cstring>

TEST_CASE("Data layer")
{
    moirai::cDataLayer data_layer;

    REQUIRE(data_layer.get_node_count() == 0);

    int32_t node_index {data_layer.add_node()};
    REQUIRE(data_layer.get_node_count() == 1);

    moirai::sNode node;
    node.pos_x = 11;
    node.pos_y = 22;
    node.size_x = 33;
    node.size_y = 44;
    strcpy(node.title, "Node Title");

    data_layer.set_node(node_index, &node);

    moirai::sNode retrieved_node {*data_layer.get_node(node_index)};

    bool equal_nodes {node.pos_x == retrieved_node.pos_x && node.pos_y == retrieved_node.pos_y && node.size_x == retrieved_node.size_x && node.size_y == retrieved_node.size_y &&
                      strcmp(node.title, retrieved_node.title) == 0};
    REQUIRE(equal_nodes);
}
