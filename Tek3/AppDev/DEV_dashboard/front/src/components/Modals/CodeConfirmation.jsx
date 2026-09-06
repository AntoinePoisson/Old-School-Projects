import React from 'react';

import { Backdrop, Button, Modal, Typography, Grow, Paper, Divider } from '@material-ui/core';
import TextField from '@material-ui/core/TextField';
import useStyles from '../../styles/ModalCodeConfirmation';


const ModalCodeConfirmation = ({open, setOpen, isInput, setInput, code}) => {

    const classes = useStyles();

    const changeValue = (event) => {
        let tmp = event.target.value;

        if (isNaN(event.target.value) || tmp.length > 6)
            return;
        setInput({...isInput, codeConfirmation: tmp});
    };

    return (
        <Modal closeAfterTransition
            className={classes.modal}
            aria-labelledby="transition-modal-title"
            aria-describedby="transition-modal-description"
            open={open}
            BackdropComponent={Backdrop}
        >
            <Grow in={open} {...({ timeout: 1000 })}>
                <Paper className={classes.Paper}>
                    <Typography variant="h5" className={classes.Title}>
                        Confirmation Account:
                    </Typography>
                    <Divider className={classes.Divider} />
                    <Typography variant="body2" className={classes.Message}>
                        You have receive an email at: <strong>{isInput && isInput.email ? isInput.email : "your.email@boxmail.com"}</strong>.
                        Please, enter below the code in your email in order to confirme your register:
                    </Typography>
                    <TextField
                        className={classes.Input}
                        required
                        id="outlined-basic"
                        label="Code Confirmation"
                        value={isInput.codeConfirmation}
                        onChange={changeValue}
                        variant="outlined"/>
                    <Button
                        className={classes.buttonValide}
                        variant="contained"
                        color="primary"
                        size="large"
                        disabled={isInput.codeConfirmation.length !== 6 ? true : false}
                        onClick={() => setOpen(false)}>
                        Valide
                    </Button>
                </Paper>
            </Grow>
        </Modal>
    );
};

export default ModalCodeConfirmation;