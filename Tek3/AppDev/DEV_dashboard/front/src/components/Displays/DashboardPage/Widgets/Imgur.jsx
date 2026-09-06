import React, { useState, useEffect } from 'react';

import { Divider, Grid, IconButton, Typography } from '@material-ui/core';
import SettingsIcon from '@material-ui/icons/Settings';
import ButtonHandleCardPosition from '../../../Tools/ButtonHandleCardPosition';

import useStyles from '../../../../styles/WidgetImgur';
import ModalSettingsImgur from '../../../Modals/ImgurSettings';
import LoaderWidget from '../../../Tools/Loader';
import BodyImgur from './Body/Imgur';

const WidgetImgur = ({index, list, setList}) => {

    const classes = useStyles();

    const [modalSettings, setOpenModalSettings] = useState(false);
    const [isLoading, setLoader] = useState(true);
    const [isData, setData] = useState({});

    useEffect(() => {
        const myInit = {
            method: "GET",
            headers: new Headers({ "Content-Type": "application/json", "Authorization": "Client-ID d247b54a5263816" }),
            mode: "cors",
            cache: "default"
        };
        fetch(`https://api.imgur.com/3/gallery/${list[index].section}/${list[index].sort}/${list[index].window}/${list[index].page}?showViral=${list[index].showViral}&mature=${list[index].showMature}&album_previews=${list[index].albumPreviews}`, myInit)
            .then(async res => {
                const result = await res.json()
                if (result.success) {
                    setData(result.data.slice(0, result.data.length / 3));
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
                    <Typography className={classes.title} variant="h5" component="h5">
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
                    <BodyImgur data={isData} />
                }
            </Grid>
            <ModalSettingsImgur
                open={modalSettings}
                setOpen={() => setOpenModalSettings(false)}
                index={index}
                list={list}
                setList={setList} />
        </Grid>
    );
};

export default WidgetImgur;