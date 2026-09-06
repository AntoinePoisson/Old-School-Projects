import React, { useState, useEffect } from 'react';

import { Divider, Grid, IconButton, Typography } from '@material-ui/core';
import SettingsIcon from '@material-ui/icons/Settings';
import ButtonHandleCardPosition from '../../../Tools/ButtonHandleCardPosition';
import LoaderWidget from '../../../Tools/Loader';

import useStyles from '../../../../styles/WidgetTemplate';
import ModalSettingsTemplate from '../../../Modals/TemplateSettings';
import BodyTemplate from './Body/Template';

const WidgetTemplate = ({index, list, setList}) => {

    const classes = useStyles();

    const [modalSettings, setOpenModalSettings] = useState(false);
    const [isLoading, ] = useState(true);

    useEffect(() => {
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [list]);

    return (
        <Grid className={classes.root}>
            <Grid container className={classes.bar}>
                <Grid item xs={10} style={{display: "flex"}}>
                    <Typography className={classes.title} variant="h5" component="h5" style={{color: list[index].color}}>
                        { list[index].title }
                    </Typography>
                </Grid>
                <Grid item xs={2}  style={{display: "flex", justifyContent: "flex-end"}}>
                    <ButtonHandleCardPosition index={index} list={list} setList={setList} />
                    <IconButton size="medium" onClick={() => setOpenModalSettings(true)}>
                        <SettingsIcon />
                    </IconButton>
                </Grid>
            </Grid>
            <Divider orientation="horizontal" style={{backgroundColor: "black"}} />
            <Grid className={classes.body}>
                { isLoading ?
                    <LoaderWidget color={list[index].color} />
                :
                    <BodyTemplate props={list[index].description} />
                }
            </Grid>
            <ModalSettingsTemplate
                open={modalSettings}
                setOpen={() => setOpenModalSettings(false)}
                index={index}
                list={list}
                setList={setList} />
        </Grid>
    );
};

export default WidgetTemplate;