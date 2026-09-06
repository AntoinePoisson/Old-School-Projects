import React from 'react';

import { Backdrop, Modal, Typography, Grow, Paper, Divider, IconButton, Button, FormControlLabel, Switch } from '@material-ui/core';
import CloseIcon from '@material-ui/icons/Close';
import useStyles from '../../styles/ModalSettingsTemplate';
import { useState } from 'react';


const ModalSettingsYoutubeSubscribers = ({open, setOpen, index, list, setList}) => {

    const classes = useStyles();

    const [time, setTime] = useState(list[index].time);

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
                        <FormControlLabel className={classes.ItemInput} label="Show time" labelPlacement="start" control={
                            <Switch label="Show time" color='primary' name="checkTime" checked={time} onChange={(event) =>
                                setTime(event.target.checked)
                            }/>
                        }/>
                        <div className={classes.ItemInput} style={{marginTop: "35px", display: "grid"}}>
                            <Button
                                variant="contained"
                                color="primary"
                                onClick={() => {
                                    var tmp = list
                                    tmp[index].time = time
                                    setList([...tmp])
                                    setOpen(false)
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

export default ModalSettingsYoutubeSubscribers;