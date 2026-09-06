import React from 'react';
import { useState } from 'react';
import { Backdrop, Modal, Typography, Grow, Paper, Divider, IconButton, Button, Switch, FormControlLabel } from '@material-ui/core';
import CloseIcon from '@material-ui/icons/Close';
import useStyles from '../../styles/ModalSettingsTemplate';


const ModalSettingsImgurProfile = ({addElement, setData}) => {

    const classes = useStyles();

    const [info, setInfo] = useState(true);

    const save = () => {
        setData({...addElement, data: {
            info: info,
            title: "Imgur profile",
            type: "ImgurProfile",
            description: "IMGURRRRRRRRRRRRRR",
            size: 6,
        }})
    };


    return (
        <Modal closeAfterTransition
            className={classes.modal}
            aria-labelledby="transition-modal-title"
            aria-describedby="transition-modal-description"
            open={true}
            BackdropComponent={Backdrop}
            onClose={() => setData({ type: "", clicked: false, data: {} })}
        >
            <Grow in={true} {...({ timeout: 500 })}>
                <Paper className={classes.Paper}>
                    <div className={classes.Bar}>
                        <Typography variant="h4" className={classes.Title}>
                            Settings
                        </Typography>
                        <IconButton size="medium" onClick={() => setData({ type: "", clicked: false, data: {} })} style={{color: "black"}}>
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
                                onClick={ save }>
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