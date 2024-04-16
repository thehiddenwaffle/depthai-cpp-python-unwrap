import depthai as dai


def build(test_pipeline: dai.Pipeline):
    input = test_pipeline.createXLinkIn()
    input.setStreamName("my_python_input")
    output = test_pipeline.createXLinkOut()
    output.setStreamName("my_python_output")
    input.out.link(output.input)
    return test_pipeline
# return 100
# msg = dai.Buffer()
# msg.setData([1, 2, 3])
# device.getInputQueue("input").send(msg)
# echoed_msg = device.getOutputQueue("output").get()
# print(echoed_msg.getData())
