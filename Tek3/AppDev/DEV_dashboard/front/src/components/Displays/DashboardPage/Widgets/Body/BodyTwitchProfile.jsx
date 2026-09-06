import React from 'react';

import { Divider, Grid } from '@material-ui/core';


const BodyTwitchProfile = ({list}) => {
console.log(list)
    return (
        <Grid
            style={{display: 'flex', flexDirection: "column"}}>
            { list.map((el, index) => (
                <Grid key={`${index}- bodywidgetTwiter`} style={{display: 'flex', flexDirection: "row", height: "max-content"}}>
                    <Grid container style={{display: "flex", flexDirection: "row"}}>
                        <Grid item xs={1} style={{display: "flex", alignContent: "center"}}>
                            <p>
                                { el.broadcaster_language }
                            </p>
                        </Grid>
                        <Grid item xs={1} style={{display: "flex", alignContent: "center", margin: "auto"}}>
                            <img src={el.thumbnail_url} alt="" style={{height: "30px"}}/>
                        </Grid>
                        <Grid item xs={2} style={{display: "flex", alignContent: "center"}}>
                            <p>
                                { el.display_name }
                            </p>
                        </Grid>
                        <Grid item xs={7} style={{display: "flex", alignContent: "center"}}>
                            <p>
                                { el.title }
                            </p>
                        </Grid>
                        <Grid item xs={1} style={{display: "flex", alignContent: "center"}}>
                            <p>
                                { el.is_live ? "Online" : "Offline" }
                            </p>
                        </Grid>
                        <Divider orientation="horizontal" style={{width: "100%"}} />
                    </Grid>
                </Grid>
              ))
            }
        </Grid>
    );
};

/*
    broadcaster_language: "fr"
    display_name: "zerator"
    game_id: "18122"
    id: "41719107"
    is_live: true
    started_at: "2020-11-29T18:06:30Z"
    tag_ids: Array [ "2a14b52e-d459-4c92-be11-5d86b898f6b6", "6f655045-9989-4ef7-8f85-1edcec42d648" ]
    thumbnail_url: "https://static-cdn.jtvnw.net/jtv_user_pictures/599b546a-c27f-4684-93ff-5eeecd01fb2b-profile_image-300x300.png"
    title: "<Gloire au héros de l'Ombreterre !> Des défis en donjon Mythique avec Lapi, Oono, Hippo et Flora"
*/

export default BodyTwitchProfile;