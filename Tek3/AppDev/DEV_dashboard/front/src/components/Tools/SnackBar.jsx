import React, { useState, useEffect } from 'react';

import Snackbar from '@material-ui/core/Snackbar';
import MuiAlert from '@material-ui/lab/Alert';


function Alert(props) {
    return <MuiAlert elevation={6} variant="filled" {...props} />;
  }

/**
 * @param message: @string
 * @param type: "error" | "warning" | "info" | "success"
 * @param duration: @Int
 **/
const MySnackBar = ({message, type, duration, recall}) => {

    const [open, setOpen] = useState(true);

    useEffect(() => {
        if (message === "" && type === "")
            setOpen(false);
        else
            setOpen(true);
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [message, type, duration, recall]);

    return (
        <div>
            <Snackbar
                open={open}
                autoHideDuration={duration ? duration : 3000}
                anchorOrigin={{
                    vertical: 'bottom',
                    horizontal: 'right',
                  }}
                onClose={() => setOpen(false)}>
                <Alert onClose={() => setOpen(false)} severity={type ? type : "info"}>
                    { message ? message : "Something Happen !" }
                </Alert>
            </Snackbar>
        </div>
    );
};

export default MySnackBar;