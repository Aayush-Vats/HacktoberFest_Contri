const htmlTopdf = require('html-pdf');

htmlPdf = (req, res) => {
    try {
        const body = req.body
        let requiredParams = ["html"];
        let verifiedData = global.verifyParams(requiredParams, body);
        if (!verifiedData.success) {
            return (global.responseFunction(res, verifiedData.statusCode, verifiedData));
        }
        
        htmlTopdf.create(body.html).toBuffer(function(err, buffer){
            if(buffer){
                global.responseFunction(res, 200, {"message": "Verified data successfully", "data": Buffer.from(buffer).toString('base64'), "success":true});
            }else{
                global.responseFunction(res, 400, {"message": "Error In converting Html to PDF", "data": err, "success":false});
            }
        });
        
    } catch (err) {
        return (global.responseFunction(res,
            500, {
                "success": false,
                "statusCode": 500,
                "message": "Something went wrong",
                "data": err
            }
        ))
    }
};
