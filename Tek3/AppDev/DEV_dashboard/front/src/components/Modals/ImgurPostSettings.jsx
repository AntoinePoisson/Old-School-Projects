import React, { useState } from 'react';

import { Backdrop, Modal, Typography, Grow, Paper, Divider, IconButton, Button, TextField } from '@material-ui/core';
import CloseIcon from '@material-ui/icons/Close';
import useStyles from '../../styles/ModalSettingsTemplate';


const ModalSettingsPostImage = ({open, setOpen, setClose, input, setInput}) => {

    const classes = useStyles();

    const [info, setInfo] = useState({name: "Cat", title: "Cute Cate", description: "Cat"});


    return (
        <Modal closeAfterTransition
            className={classes.modal}
            aria-labelledby="transition-modal-title"
            aria-describedby="transition-modal-description"
            open={open}
            BackdropComponent={Backdrop}
            onClose={() => !setClose && setInfo({name: "", title: "", description: ""})}
        >
            <Grow in={open} {...({ timeout: 500 })}>
                <Paper className={classes.Paper}>
                    <div className={classes.Bar}>
                        <Typography variant="h4" className={classes.Title}>
                            Upload Image
                        </Typography>
                        <IconButton size="medium" onClick={() => !setClose && setInfo({name: "", title: "", description: ""})} style={{color: "black"}}>
                            <CloseIcon />
                        </IconButton>
                    </div>
                    <Divider className={classes.Divider} />
                    <div className={classes.Body}>
                        <div className={classes.ItemInput}>
                            <TextField
                                id="standard-basic"
                                label="Name Picture"
                                value={info.name}
                                onChange={(event) => setInfo({...info, name: event.target.value})} />
                        </div>
                        <div className={classes.ItemInput}>
                            <TextField
                                id="standard-basic"
                                label="Title Picture"
                                value={info.title}
                                onChange={(event) => setInfo({...info, title: event.target.value})} />
                        </div>
                        <div className={classes.ItemInput}>
                            <TextField
                                id="standard-basic"
                                label="Description Picture"
                                value={info.description}
                                onChange={(event) => setInfo({...info, description: event.target.value})} />
                        </div>
                        <div className={classes.ItemInput} style={{marginTop: "35px", display: "grid"}}>
                            <Button
                                variant="contained"
                                color="primary"
                                disabled={!info.name.length || !info.description.length || !info.title.length}
                                onClick={() => {!setInput({...input, complete: true, name: info.name, title: info.title, description: info.description, open: false}) && setInfo({name: "", title: "", description: ""})}}>
                                Valide
                            </Button>
                        </div>
                    </div>
                </Paper>
            </Grow>
        </Modal>
    );
};

export default ModalSettingsPostImage;