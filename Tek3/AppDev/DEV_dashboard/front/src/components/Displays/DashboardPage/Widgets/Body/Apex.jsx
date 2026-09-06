import React from 'react';

import { Avatar, Grid, Typography } from '@material-ui/core';


const BodyTemplate = ({data}) => {

    return (
        <Grid style={{ margin: '5px' }}>
            <Grid container direction='row'>
                <Grid item xs={8}>
                    <Typography variant='h4'>{ data.global.name }</Typography>
                    <Grid container>
                        <Avatar src={ data.global.rank.rankImg } style={{ height: '70px', width: '70px' }} alt='rank'/>
                        <Typography variant='h5' style={{ marginLeft: '10px', display: 'flex', flexDirection: 'column', justifyContent: 'center'}}>Rank score: { data.global.rank.rankScore }</Typography>
                    </Grid>
                    <Grid container direction='row' style={{ marginTop: '10px'}}>
                        <Grid item xs={4} style={{display: 'flex', flexDirection: 'column'}}>
                                <Typography align='center'>Total kills</Typography>
                                <Typography align='center'>{ data.total.kills.value }</Typography>
                        </Grid>
                        <Grid item xs={4} style={{display: 'flex', flexDirection: 'column'}}>
                                <Typography align='center'>Damage</Typography>
                                <Typography align='center'>{ data.total.damage ? data.total.damage.value : "N/A" }</Typography>
                        </Grid>
                        <Grid item xs={4} style={{display: 'flex', flexDirection: 'column'}}>
                                <Typography align='center'>KD</Typography>
                                <Typography align='center'>{ data.total.kd.value }</Typography>
                        </Grid>
                    </Grid>
                </Grid>
                <Grid item xs={4}>
                    <img src={ data.legends.selected.ImgAssets.icon } style={{ height: '200px', width: '200px', objectFit: 'contain' }} alt=''/>
                </Grid>
            </Grid>
        </Grid>
    );
};

export default BodyTemplate;