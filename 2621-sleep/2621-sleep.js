/**
 * @param {number} millis
 */
async function sleep(millis) {
    return new Promise((resolve, reject) => {
        let condition = true;
        
        setTimeout(() => {
            if(condition) {
                resolve("Promise Fulfilled!");
            }else {
                reject("Promise rejected!")
            }
        }, millis)
    })
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */