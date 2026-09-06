import React from 'react';
import { useState } from 'react';
import { Backdrop, Modal, Typography, Grow, Paper, Divider, IconButton, Button, TextField } from '@material-ui/core';
import CloseIcon from '@material-ui/icons/Close';
import useStyles from '../../styles/ModalSettingsTemplate';


const ModalSettingsApex = ({open, setOpen, index, list, setList}) => {

    const classes = useStyles();

    const [user, setUser] = useState(list[index].user);

    return (
        <Modal closeAfterTransition
            className={classes.modal}
            aria-labelledby="transition-modal-title"
            aria-describedby="transition-modal-description"
            open={open}
            BackdropComponent={Backdrop}
            onClose={() => setOpen(false)}
        >
            <Grow in={open} {...({ timeout: 500 })}>
                <Paper className={classes.Paper}>
                    <div className={classes.Bar}>
                        <Typography variant="h4" className={classes.Title}>
                            Settings
                        </Typography>
                        <IconButton size="medium" onClick={() => setOpen(false)} style={{color: "black"}}>
                            <CloseIcon />
                        </IconButton>
                    </div>
                    <Divider className={classes.Divider} />
                    <div className={classes.Body}>
                        <div className={classes.ItemInput}>
                            <TextField id="standard-basic" label="Username" value={ user } onChange={ (event) => {
                                setUser(event.target.value)
                            }}/>
                        </div>
                        <div className={classes.ItemInput} style={{marginTop: "35px", display: "grid"}}>
                            <Button
                                variant="contained"
                                color="primary"
                                onClick={() => {
                                    var tmp = list
                                    tmp[index].user = user
                                    setList([...tmp])
                                    setOpen(false);
                                }}>
                                Valide
                            </Button>
                        </div>
                    </div>
                </Paper>
            </Grow>
        </Modal>
    );
};

export default ModalSettingsApex;