import React from 'react';

import { Backdrop, Modal, Typography, Grow, Paper, Divider, IconButton, Button, FormControlLabel, Switch } from '@material-ui/core';
import CloseIcon from '@material-ui/icons/Close';
import useStyles from '../../styles/ModalSettingsImgur';
import { useState } from 'react';


const ModalSettingsYoutubeSubscriber = ({addElement, setData}) => {

    const classes = useStyles();

    const [time, setTime] = useState(false);
    const [input, ] = useState({
            time: false,
            title: "Youtube subscriber",
            type: "YoutubeSubscriber",
            description: "Show your latest sub",
            size: 6,
        })

    const confirmeChange = () => {
        setData({...addElement, data: {...input}});
    }

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
                <Paper className={classes.Paper} style={{width: "365px"}}>
                    <div className={classes.Bar}>
                        <Typography variant="h4" className={classes.Title}>
                            Setting
                        </Typography>
                        <IconButton size="medium" onClick={() => setData({ type: "", clicked: false, data: {} })} style={{color: "black"}}>
                            <CloseIcon />
                        </IconButton>
                    </div>
                    <Divider className={classes.Divider} />
                    <div className={classes.Body}>
                        <FormControlLabel className={classes.ItemInput} label="Show time" labelPlacement="start" control={
                            <Switch label="Show time" color='primary' checked={time} onChange={(event) =>
                                setTime(event.target.checked)
                            }/>
                        }/>
                        <div className={classes.ItemInput} style={{marginTop: "35px", display: "grid"}}>
                            <Button
                                variant="contained"
                                color="primary"
                                onClick={confirmeChange}>
                                Valide
                            </Button>
                        </div>
                    </div>
                </Paper>
            </Grow>
        </Modal>
    );
};

export default ModalSettingsYoutubeSubscriber;