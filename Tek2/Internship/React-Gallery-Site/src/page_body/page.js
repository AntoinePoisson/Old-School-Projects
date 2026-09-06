import React, { Component } from 'react';
import Select from '@material-ui/core/Select';
import MenuItem from '@material-ui/core/MenuItem';
import DisplayData from './displayData';
import MyButton from './buttom/myButton';
import './style.css'

class Page extends Component {
    state = {
        currentElement: 0,
        nbrElement: 10,
        totalElement: 0,
        data: null,
        selectedOption: 10,
    }

    componentDidMount = () => { this.refreshPage() }

    componentDidUpdate(prevProps, prevState) {
        if (this.state.currentElement !== prevState.currentElement) {
            this.refreshPage();
        }
    }
    
    goToBegin = () => this.setState({ currentElement: 0})

    previousPage = (currentElement, nbrElement) => {
        if (currentElement - nbrElement >= 0)
            this.setState({ currentElement: currentElement - nbrElement });
    }

    nextPage = (currentElement, nbrElement, totalElement) => {
        if (currentElement + nbrElement < totalElement) {
            this.setState({ currentElement: currentElement + nbrElement });
        }
    }

    goToEnd = (nbrElement, totalElement) => {
        if (totalElement - nbrElement >= 0)
            this.setState({ currentElement: totalElement - nbrElement })
        else
            this.setState({ currentElement: 0 })    
    }

    refreshPage = () => {
        fetch(`http://jsonplaceholder.typicode.com/photos?_start=${this.state.currentElement}&_limit=${this.state.nbrElement}`)
            .then(async res => {
            const total = await res.headers.get("x-total-count");
            const info = await res.json();

            this.setState({
                totalElement: parseInt(total),
                data: info
            });
        });
    }

    handleChange = (event) => {
        this.setState({
            nbrElement: event.target.value,
            selectedOption : event.target.value,
        }, this.refreshPage);
        
    }

    render() {
        return (
            <div>
                <MyButton
                    current={this.state.currentElement}
                    total={this.state.totalElement}
                    nbrElement={this.state.nbrElement}
                    cas={true}
                    gotoend={this.goToEnd}
                    next={this.nextPage}
                    prev={this.previousPage}
                    gotobegin={this.goToBegin}
                />
                <Select
                    className='selector'
                    value={this.state.selectedOption}
                    onChange={this.handleChange}>
                        <MenuItem value={10}>10</MenuItem>
                        <MenuItem value={30}>30</MenuItem>
                        <MenuItem value={50}>50</MenuItem>
                        <MenuItem value={100}>100</MenuItem>
                        <MenuItem value={this.state.totalElement}>Tout</MenuItem>
                </Select>
                { this.state.data && <DisplayData data={this.state.data}/> }
                <MyButton
                    current={this.state.currentElement}
                    total={this.state.totalElement}
                    nbrElement={this.state.nbrElement}
                    cas={false}
                    gotoend={this.goToEnd}
                    next={this.nextPage}
                    prev={this.previousPage}
                    gotobegin={this.goToBegin}
                />
            </div>
        );
    }
}

export default Page;
