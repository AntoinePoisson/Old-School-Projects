export const FetchGET = (path, doFuncSuccess, doFuncError, options) => {
    fetch(`${process.env.REACT_APP_URL_BACK}${path}`, options)
        .then(async (res) => {
            doFuncSuccess(await res.json(), res.status)
        }).catch((err) => {
            doFuncError()
            console.log(err)
        });
};

export const FetchPOST = (path, body, doFuncSuccess, doFuncError) => {
    fetch(`${process.env.REACT_APP_URL_BACK}${path}`, {
        method: 'POST',
        headers: {
            'Accept': 'application/json',
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(body)
    })
        .then(async (res) => {
            doFuncSuccess(await res.json(), res.status)
        }).catch((err) => {
            if (doFuncError != null) {
                doFuncError()
            }
            console.log(err)
        });
};
