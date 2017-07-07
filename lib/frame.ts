import * as blessed from 'blessed';

import { Config } from '../config/config.type';

export default class Frame {
	config: Config;

	constructor (config: Config) {
		this.config = config;
	}

	init (): void {
		console.log(this.config.name);
	}
}
