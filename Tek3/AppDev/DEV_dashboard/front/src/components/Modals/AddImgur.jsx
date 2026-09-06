import React from 'react';

import { Backdrop, Modal, Typography, Grow, Paper, Divider, IconButton, Select, InputLabel, FormControl, TextField, FormControlLabel, Switch, Button } from '@material-ui/core';
import CloseIcon from '@material-ui/icons/Close';
import useStyles from '../../styles/ModalSettingsImgur';
import { useState } from 'react';


const ModalSettingsImgur = ({addElement, setData}) => {

    const classes = useStyles();

    const [input, setInput] = useState({
            section: "hot",
            sort: "viral",
            window: "day",
            page: 1,
            showViral: "true",
            showMature: "false",
            title: "Imgur",
            type: "Imgur",
            description: "Imgur, list Picture",
            size: 6,
        })

    const confirmeChange = () => {
        setData({...addElement, data: {...input, page: input.page.toString()}});
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
                            Add Imgur Widget
                        </Typography>
                        <IconButton size="medium" onClick={() => setData({ type: "", clicked: false, data: {} })} style={{color: "black"}}>
                            <CloseIcon />
                        </IconButton>
                    </div>
                    <Divider className={classes.Divider} />
                    <div className={classes.Body}>
                        <FormControl className={classes.ItemInput}>
                            <InputLabel htmlFor="age-native-simple">Section</InputLabel>
                            <Select
                                native
                                value={input.section}
                                onChange={(event) => setInput({...input, section: event.target.value})}
                                inputProps={{
                                    name: 'Section',
                                    id: 'age-native-simple',
                                }}>
                                <option value={"hot"}>Hot</option>
                                <option value={"top"}>Top</option>
                                <option value={"user"}>User</option>
                            </Select>
                        </FormControl>
                        <FormControl className={classes.ItemInput}>
                            <InputLabel htmlFor="age-native-simple">Sort</InputLabel>
                            <Select
                                native
                                value={input.sort}
                                onChange={(event) => setInput({...input, sort: event.target.value})}
                                inputProps={{
                                    name: 'Sort',
                                    id: 'age-native-simple',
                                }}>
                                <option value={"viral"}>Viral</option>
                                <option value={"top"}>Top</option>
                                <option value={"time"}>Time</option>
                                <option value={"rising"}>Rising</option>
                            </Select>
                        </FormControl>
                        <FormControl className={classes.ItemInput}>
                            <InputLabel htmlFor="age-native-simple">Window</InputLabel>
                            <Select
                                native
                                value={input.window}
                                onChange={(event) => setInput({...input, window: event.target.value})}
                                inputProps={{
                                    name: 'Window',
                                    id: 'age-native-simple',
                                }}>
                                <option value={"day"}>Day</option>
                                <option value={"week"}>Week</option>
                                <option value={"month"}>Month</option>
                                <option value={"year"}>Year</option>
                                <option value={"all"}>All</option>
                            </Select>
                        </FormControl>
                        <FormControl className={classes.ItemInput}>
                            <InputLabel htmlFor="age-native-simple">Size</InputLabel>
                            <Select
                                native
                                value={input.size}
                                onChange={(event) => setInput({...input, size: event.target.value})}
                                inputProps={{
                                    name: 'Size',
                                    id: 'age-native-simple',
                                }}>
                                <option value={4}>Small</option>
                                <option value={6}>Medium</option>
                                <option value={12}>Large</option>
                            </Select>
                        </FormControl>
                        <div className={classes.ItemInput}>
                            <TextField
                                id="standard-basic"
                                label="Page"
                                value={input.page}
                                onChange={(event) => !isNaN(event.target.value) && event.target.value <= 100 &&setInput({...input, page: event.target.value})} />
                        </div>
                        <div className={classes.ItemInput}>
                            <FormControlLabel
                                label="Show Viral"
                                control={
                                    <Switch
                                        checked={input.showViral === "true"}
                                        onChange={() => setInput({...input, showViral: (input.showViral === "true" ? "false" : "true")})}
                                        name="checkedB"
                                        color="primary"
                                    />
                                } />
                        </div>
                        <div className={classes.ItemInput}>
                            <FormControlLabel
                                label="Show Mature"
                                control={
                                    <Switch
                                        checked={input.showMature === "true" ? true : false}
                                        onChange={() => setInput({...input, showMature: (input.showMature === "true" ? "false" : "true")})}
                                        name="checkedB"
                                        color="primary"
                                    />
                                } />
                        </div>
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

export default ModalSettingsImgur;