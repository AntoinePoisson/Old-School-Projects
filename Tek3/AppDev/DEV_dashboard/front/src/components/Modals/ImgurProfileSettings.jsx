import React from 'react';

import { Backdrop, Modal, Typography, Grow, Paper, Divider, IconButton, Button, Switch, FormControlLabel } from '@material-ui/core';
import CloseIcon from '@material-ui/icons/Close';
import useStyles from '../../styles/ModalSettingsTemplate';
import { useState } from 'react';


const ModalSettingsImgurProfile = ({open, setOpen, index, list, setList}) => {

    const classes = useStyles();

    const [info, setInfo] = useState(list[index].info);

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
                        <FormControlLabel className={classes.ItemInput} label="Show my info" labelPlacement="start" control={
                            <Switch color='primary' name="checkInfo" checked={info} onChange={(event) =>
                                setInfo(event.target.checked)
                            }/>
                        }/>
                        <div className={classes.ItemInput} style={{marginTop: "35px", display: "grid"}}>
                            <Button
                                variant="contained"
                                color="primary"
                                onClick={() => {
                                    var tmp = list
                                    tmp[index].info = info
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

export default ModalSettingsImgurProfile;