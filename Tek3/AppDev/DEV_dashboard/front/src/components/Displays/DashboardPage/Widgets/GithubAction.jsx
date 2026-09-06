import React, { useState, useEffect, useContext } from 'react';

import { Divider, Grid, IconButton, Typography } from '@material-ui/core';
import SettingsIcon from '@material-ui/icons/Settings';
import ButtonHandleCardPosition from '../../../Tools/ButtonHandleCardPosition';
import LoaderWidget from '../../../Tools/Loader';

import useStyles from '../../../../styles/WidgetTemplate';
import ModalSettingsGithubIsssue from '../../../Modals/GithubIssueSettings';
import BodyGithubIssue from './Body/GithubAction';
import DataContext from '../../../../contexts/dataContext';

const WidgetGithubAction = ({index, list, setList}) => {

    const classes = useStyles();

    const [modalSettings, setOpenModalSettings] = useState(false);
    const [isLoading, setLoader] = useState(true);
    const [isData, setData] = useState({});
    const [dataState] = useContext(DataContext);

    useEffect(() => {
        const myInit = {
            method: "GET",
            headers: new Headers({ "Content-Type": "application/json", "Authorization": `token ${dataState.TokenServices.Github}`}),
            mode: "cors",
            cache: "default"
        };
        fetch(`https://api.github.com/repos/${list[index].repo}/actions/runs`, myInit)
            .then(async res => {
                const result = await res.json()
                if (!result.message) {
                    setData(result)
                    setLoader(false);
                } else {
                    console.error(result)
                }
            })
            .catch((error) => {
                console.error(error)
            })
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [list[index]]);

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
                    <BodyGithubIssue data={isData.workflow_runs} />
                }
            </Grid>
            <ModalSettingsGithubIsssue
                open={modalSettings}
                setOpen={() => setOpenModalSettings(false)}
                index={index}
                list={list}
                setList={setList} />
        </Grid>
    );
};

export default WidgetGithubAction;