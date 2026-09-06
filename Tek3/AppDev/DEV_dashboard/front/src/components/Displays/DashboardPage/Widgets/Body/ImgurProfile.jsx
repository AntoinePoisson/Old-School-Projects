import React from 'react';

import { Grid, GridList, GridListTile, Typography, Avatar } from '@material-ui/core';


const BodyImgurProfile = ({data, profile}) => {

    return (
        <Grid>
            { profile.avatar ?
                <Grid container direction='row'>
                    <Avatar src={ profile.avatar}/>
                    <Typography variant='h4' style={{ marginLeft: '10px'}}>{ profile.url }</Typography>
                </Grid>
            :
                <div/>
            }
            <GridList cellHeight={160} cols={3}>
                { data.map((tile, index) => {
                    if (tile && (tile.type ? (tile.type === "image/jpeg") : (tile.images[0].type === "image/jpeg"))) {
                        return (
                            <GridListTile key={`${tile.id}-${index}`} cols={1}>
                                <img src={tile.type ? tile.link : tile.images[0].link} alt={""} />
                            </GridListTile>
                        );
                    } else {
                        return (<div key={`${tile.id}-${index}`} style={{height: "0px", width: "0px", padding: "0px"}}/>);
                    }
                })
                }
            </GridList>
        </Grid>
    );
};

export default BodyImgurProfile;