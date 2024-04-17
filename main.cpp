#include "PybindEmbedded.hpp"


int main() {
    std::cout << "Starting pybind" << std::endl;

    std::string filePath = __FILE__;
    std::string dirPath = filePath.substr(0, filePath.find_last_of("/\\"));
    std::string pythonPath("PYTHONPATH=");
    pythonPath.append(dirPath);
    putenv(const_cast<char *>(pythonPath.c_str()));

    py::scoped_interpreter guard{}; // start interpreter, dies when out of scope

    auto dai = py::module_::import("depthai_emb");
    py::function attach_pipeline =
            // cast from 'object' to 'function - use `borrow` (copy) or `steal` (move)
            py::reinterpret_borrow<py::function>(
                    py::module_::import("pipeline").attr("build")
            );

    auto dev = dai.attr("Pipeline");
    auto py_pipeline = dev();
    py::object result = attach_pipeline(py_pipeline);
    auto *back_in_cpp = result.cast<dai::Pipeline *>();
    const dai::Pipeline firm_obj = back_in_cpp->clone();
    std::vector<std::shared_ptr<const dai::Node>> nodes = firm_obj.getAllNodes();
    for(auto node : nodes){
        std::string name = node.get()->getName();
    }

    auto* cls = new dai::Device(firm_obj);
    std::shared_ptr<dai::DataInputQueue> in = cls->getInputQueue("my_python_input");
    std::shared_ptr<dai::DataOutputQueue> out = cls->getOutputQueue("my_python_output");
    auto* test = new dai::Buffer();
    std::vector<std::uint8_t> values = {1, 2, 3};
    test->setData(values);
    in->send(*test);
    std::vector<std::uint8_t> output = out->get().get()->getRaw().get()->data;
    assert(values == output);
    return 0;
}